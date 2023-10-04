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
  static InvokeEvent* Create(const AtomicString& type,
                             Event::Cancelable cancelable,
                             const HTMLElement* RelatedTarget,
                             const AtomicString& action) {
    auto* event = MakeGarbageCollected<InvokeEvent>(type, cancelable, RelatedTarget,
                                                    action);
    DCHECK(!event->bubbles());
    return event;
  }

  InvokeEvent();
  InvokeEvent(const AtomicString& type,
              Event::Cancelable cancelable,
              const HTMLElement* RelatedTarget,
              const AtomicString& action);
  InvokeEvent(const AtomicString& type, const InvokeEventInit* initializer);
  ~InvokeEvent() override;

  const String& oldState() const;
  const String& newState() const;

  const AtomicString& InterfaceName() const override;

  void Trace(Visitor*) const override;

 private:
  String old_state_;
  String new_state_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TOGGLE_EVENT_H_
