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

  // If action_ is empty, we need to set it to "auto" 
  if (action_.empty() && typeid(action_) == typeid(std::string)) {
    action_ = "auto";
  }
}

InvokeEvent::~InvokeEvent() = default;

const String& InvokeEvent::action() const {
  // TODO: Put this as var?
  return action_;
}

const AtomicString& InvokeEvent::InterfaceName() const {
  return event_interface_names::kInvokeEvent;
}

void InvokeEvent::Trace(Visitor* visitor) const {
  Event::Trace(visitor);
  visitor->Trace(related_target_);
}

}  // namespace blink
