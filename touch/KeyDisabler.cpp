//
// SPDX-FileCopyrightText: The LineageOS Project
// SPDX-License-Identifier: Apache-2.0
//

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>

#include "KeyDisabler.h"

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace implementation {

KeyDisabler::KeyDisabler() {
    mHasKeyDisabler = false;

    mFingerprintNavigation = IFingerprintNavigation::getService();
    if (mFingerprintNavigation != nullptr)
        mHasKeyDisabler = true;
}

// Methods from ::vendor::lineage::touch::V1_0::IKeyDisabler follow.
Return<bool> KeyDisabler::isEnabled() {
    if (!mHasKeyDisabler) return false;

    return mFingerprintNavigation->isEnabled();
}

Return<bool> KeyDisabler::setEnabled(bool enabled) {
    if (!mHasKeyDisabler) return false;

    mFingerprintNavigation->setNavigation(!enabled);
    return true;
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
