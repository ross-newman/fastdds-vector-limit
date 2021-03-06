// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file testPublisher.cpp
 * This file contains the implementation of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */

#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/publisher/Publisher.h>

#include <fastrtps/Domain.h>

#include <chrono>
#include <thread>

#include "testPublisher.h"

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

testPublisher::testPublisher() : mp_participant(nullptr), mp_publisher(nullptr) {}

testPublisher::~testPublisher() { Domain::removeParticipant(mp_participant); }

bool testPublisher::init() {
  // Create RTPSParticipant

  ParticipantAttributes PParam;
  PParam.rtps.setName("Participant_publisher");  // You can put here the name you want
  mp_participant = Domain::createParticipant(PParam);
  if (mp_participant == nullptr) {
    return false;
  }

  // Register the type

  Domain::registerType(mp_participant, static_cast<TopicDataType*>(&myType));

  // Create Publisher

  PublisherAttributes Wparam;
  Wparam.topic.topicKind = NO_KEY;
  Wparam.topic.topicDataType = myType.getName();  // This type MUST be registered
  Wparam.topic.topicName = "testPubSubTopic";

  mp_publisher = Domain::createPublisher(mp_participant, Wparam, static_cast<PublisherListener*>(&m_listener));

  if (mp_publisher == nullptr) {
    return false;
  }

  std::cout << "Publisher created, waiting for Subscribers." << std::endl;
  return true;
}

void testPublisher::PubListener::onPublicationMatched(Publisher* pub, MatchingInfo& info) {
  (void)pub;

  if (info.status == MATCHED_MATCHING) {
    n_matched++;
    std::cout << "Publisher matched" << std::endl;
  } else {
    n_matched--;
    std::cout << "Publisher unmatched" << std::endl;
  }
}
#define LOREM_IPSUM_LONG                                                                                               \
  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore "     \
  "magna aliqua. Pretium fusce id velit ut tortor. Nunc pulvinar sapien et ligula. Fringilla ut morbi tincidunt "      \
  "augue interdum. Eget mauris pharetra et ultrices neque ornare aenean euismod elementum. Laoreet id donec ultrices " \
  "tincidunt arcu non sodales neque. In cursus turpis massa tincidunt. Viverra nam libero justo laoreet sit amet "     \
  "cursus sit. Bibendum at varius vel pharetra vel turpis nunc eget. Pellentesque diam volutpat commodo sed. Odio ut " \
  "enim blandit volutpat maecenas. Adipiscing at in tellus integer feugiat scelerisque. Velit ut tortor pretium "      \
  "viverra. Eu augue ut lectus arcu bibendum at varius. Bibendum at varius vel pharetra. Suscipit adipiscing "         \
  "bibendum est ultricies integer quis. Proin sagittis nisl rhoncus mattis rhoncus urna neque. Nisi est sit amet "     \
  "facilisis. Enim ut tellus elementum sagittis vitae et leo duis ut. Id velit ut tortor pretium viverra suspendisse " \
  "potenti nullam ac."

void testPublisher::run() {
  while (m_listener.n_matched == 0) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));  // Sleep 250 ms
  }

  // Publication code
  I_Kit_Logging st;

  /* Initialize your structure here */
  int msgsent = 0;
  std::string test = LOREM_IPSUM_LONG;
  for (int i = 5; i < (int)test.length(); i++) {
    T_Payload string;
    std::copy(test.begin(), test.begin() + i, std::back_inserter(string));
    st.A_payload(string);
    if (!mp_publisher->write(&st)) std::cout << "Failed length " << i << std::endl;
    ++msgsent;
  }
}
