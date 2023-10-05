// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TOGGLE_EVENT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TOGGLE_EVENT_H_

#include "third_party/blink/renderer/core/dom/events/event.h"

namespace blink {

class InvokeEventInit;

class InvokeEvent final : public Event {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static InvokeEvent* Create(const AtomicString& type,
                             const InvokeEventInit* initializer) {
    return MakeGarbageCollected<InvokeEvent>(type, initializer);
  }

  InvokeEvent();
  InvokeEvent(const AtomicString& type, const InvokeEventInit* initializer);
  ~InvokeEvent() override;

  const AtomicString& InterfaceName() const override;

  void Trace(Visitor*) const override;

  const String& action() const;

  EventTarget* relatedTarget() const { return related_target_.Get(); }
  void SetRelatedTarget(EventTarget* related_target) {
    related_target_ = related_target;
  }

 private:
  Member<EventTarget> related_target_;
  String action_; 
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TOGGLE_EVENT_H_
