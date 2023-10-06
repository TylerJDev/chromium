// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/events/invoke_event.h"

#include "third_party/blink/renderer/bindings/core/v8/v8_invoke_event_init.h"
#include "third_party/blink/renderer/core/dom/events/event.h"
#include "third_party/blink/renderer/core/event_interface_names.h"

namespace blink {

InvokeEvent::InvokeEvent() = default;

InvokeEvent::InvokeEvent(const AtomicString& type,
                         const InvokeEventInit* initializer)
    : Event(type, initializer) {
  if (initializer->hasRelatedTarget()) {
    related_target_ = initializer->relatedTarget();
  }
  if (initializer->hasAction()) {
    action_ = initializer->action();
  }
  if (action_.empty()) {
    action_ = "auto";
  }
}

InvokeEvent::~InvokeEvent() = default;

const String& InvokeEvent::action() const {
  return action_;
}

const AtomicString& InvokeEvent::InterfaceName() const {
  return event_interface_names::kInvokeEvent;
}

void InvokeEvent::Trace(Visitor* visitor) const {
  visitor->Trace(related_target_);
  Event::Trace(visitor);
}

}  // namespace blink