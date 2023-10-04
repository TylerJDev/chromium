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
                         const HTMLElement* relatedTarget,
                         const AtomicString& action)
    : Event(type, Bubbles::kNo, Cancelable::kYes),
      action_(action),
      related_target_ = related_target {}

InvokeEvent::InvokeEvent(const AtomicString& type,
                         const InvokeEventInit* initializer)
    : Event(type, initializer) {
  if (initializer->hasRelatedTarget()) {
    related_target_ = initializer->relatedTarget();
  }
  if (initializer->hasAction()) {
    action_ = initializer->action();
  }
}

InvokeEvent::~InvokeEvent() = default;

const HTMLElement& InvokeEvent::relatedTarget() const {
  return null;
}

const AtomicString& InvokeEvent::action() const {
  // TODO: Put this as var?
  return AtomicString("auto");
}

const AtomicString& InvokeEvent::InterfaceName() const {
  return event_interface_names::kInvokeEvent;
}

void InvokeEvent::Trace(Visitor* visitor) const {
  Event::Trace(visitor);
}

}  // namespace blink
