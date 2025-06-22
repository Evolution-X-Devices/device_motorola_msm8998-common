//
// SPDX-FileCopyrightText: The LineageOS Project
// SPDX-License-Identifier: Apache-2.0
//

#ifndef VENDOR_LINEAGE_TOUCH_V1_0_KEYDISABLER_H
#define VENDOR_LINEAGE_TOUCH_V1_0_KEYDISABLER_H

#include <com/fingerprints/extension/1.0/IFingerprintNavigation.h>
#include <vendor/lineage/touch/1.0/IKeyDisabler.h>

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace implementation {

using ::android::hardware::Return;
using ::android::sp;
using ::com::fingerprints::extension::V1_0::IFingerprintNavigation;

class KeyDisabler : public IKeyDisabler {
  public:
    KeyDisabler();

    // Methods from ::vendor::lineage::touch::V1_0::IKeyDisabler follow.
    Return<bool> isEnabled() override;
    Return<bool> setEnabled(bool enabled) override;

  private:
    bool mHasKeyDisabler;
    sp<IFingerprintNavigation> mFingerprintNavigation;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_TOUCH_V1_0_KEYDISABLER_H
