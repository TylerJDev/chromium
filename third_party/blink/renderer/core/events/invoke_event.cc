// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/events/toggle_event.h"

#include "third_party/blink/renderer/bindings/core/v8/v8_toggle_event_init.h"
#include "third_party/blink/renderer/core/dom/events/event.h"
#include "third_party/blink/renderer/core/event_interface_names.h"

namespace blink {

InvokeEvent::InvokeEvent() = default;

InvokeEvent::InvokeEvent(const AtomicString& type,
                         Event::Cancelable cancelable,
                         const HTMLElement* RelatedTarget,
                         const AtomicString& action)
    : Event(type, Bubbles::kNo, cancelable),
      old_state_(old_state),
      new_state_(new_state) {}

InvokeEvent::InvokeEvent(const AtomicString& type,
                         const InvokeEventInit* initializer)
    : Event(type, initializer) {
  if (initializer->hasOldState()) {
    old_state_ = initializer->oldState();
  }
  if (initializer->hasNewState()) {
    new_state_ = initializer->newState();
  }
}

InvokeEvent::~InvokeEvent() = default;

const HTMLElement& InvokeEvent::RelatedTarget() const {
  return null;
}

const AtomicString& InvokeEvent::action() const {
  return null;
}

const AtomicString& InvokeEvent::InterfaceName() const {
  return event_interface_names::kInvokeEvent;
}

void InvokeEvent::Trace(Visitor* visitor) const {
  Event::Trace(visitor);
}

}  // namespace blink
