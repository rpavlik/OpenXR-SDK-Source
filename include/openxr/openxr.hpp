// *********** THIS FILE IS GENERATED - DO NOT EDIT ***********
//     See cpp_generator.py for modifications
// ************************************************************

#ifndef OPENXR_HPP_
#define OPENXR_HPP_ 1

/*
** Copyright (c) 2017-2019 The Khronos Group Inc.
** Copyright (c) 2019 Collabora, Ltd.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/

#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
#include <memory>
#include <vector>
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

// Fix name collisions from noisy includes
#ifdef Success
#undef Success
#endif

#if !defined(OPENXR_HPP_ASSERT)
#include <cassert>
#define OPENXR_HPP_ASSERT assert
#endif

// 32-bit OpenXR is not typesafe for handles, so don't allow copy constructors
// on this platform by default. To enable this feature on 32-bit platforms
// please define OPENXR_HPP_TYPESAFE_CONVERSION
#if defined(__LP64__) || defined(_WIN64) ||                                    \
    (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) ||         \
    defined(__ia64) || defined(_M_IA64) || defined(__aarch64__) ||             \
    defined(__powerpc64__)
#if !defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_CONVERSION
#endif
#endif

#if !defined(OPENXR_HPP_INLINE)
#if defined(__clang___)
#if __has_attribute(always_inline)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#else
#define OPENXR_HPP_INLINE inline
#endif
#elif defined(__GNUC__)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#elif defined(_MSC_VER)
#define OPENXR_HPP_INLINE inline
#else
#define OPENXR_HPP_INLINE inline
#endif
#endif

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_EXPLICIT
#else
#define OPENXR_HPP_TYPESAFE_EXPLICIT explicit
#endif

#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define OPENXR_HPP_CONSTEXPR
#else
#define OPENXR_HPP_CONSTEXPR constexpr
#endif

//! @todo set this to constexpr in c++14
#define OPENXR_HPP_SWITCH_CONSTEXPR

#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif

#define OPENXR_HPP_STRINGIFY2(text) #text
#define OPENXR_HPP_STRINGIFY(text) OPENXR_HPP_STRINGIFY2(text)
#define OPENXR_HPP_NAMESPACE_STRING OPENXR_HPP_STRINGIFY(OPENXR_HPP_NAMESPACE)

namespace OPENXR_HPP_NAMESPACE {

using Bool32 = XrBool32;
using Duration = XrDuration;
using Path = XrPath;
using SystemId = XrSystemId;
using Time = XrTime;
using Version = XrVersion;

} // namespace OPENXR_HPP_NAMESPACE

/*!
 * @brief Namespace containing all openxr.hpp entities.
 *
 * If the default namespace `xr` isn't suitable, you can define
 * OPENXR_HPP_NAMESPACE to a different name before including this header.
 */
namespace OPENXR_HPP_NAMESPACE {
// Forward declaration
class DispatchLoaderDynamic;

/*!
 * @defgroup dispatch Dispatch classes
 * @brief Classes providing a method or function pointer member for OpenXR APIs.
 *
 * The classes provided here are useful basic classes, but all places that can
 * take a dispatch class are templated to be able to accept any class that meets
 * the requirements.
 */

/*!
 * @brief Dispatch class for OpenXR core functions that uses exported,
 * statically-available symbols.
 *
 * Not for use in game engines or other multi-module software where different
 * modules might want newer OpenXR APIs. If this is used, all parts of an
 * application must build against and use the same loader library.
 *
 * Does not provide extension functions because those are not exported from the
 * loader library.
 *
 * @ingroup dispatch
 */
class DispatchLoaderStatic {
public:
  /*!
   * @name Core Commands
   * @{
   */

  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) const {
    return ::xrGetInstanceProcAddr(instance, name, function);
  }
  XrResult
  xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                uint32_t *propertyCountOutput,
                                XrApiLayerProperties *properties) const {
    return ::xrEnumerateApiLayerProperties(propertyCapacityInput,
                                           propertyCountOutput, properties);
  }
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) const {
    return ::xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) const {
    return ::xrCreateInstance(createInfo, instance);
  }
  XrResult xrDestroyInstance(XrInstance instance) const {
    return ::xrDestroyInstance(instance);
  }
  XrResult
  xrGetInstanceProperties(XrInstance instance,
                          XrInstanceProperties *instanceProperties) const {
    return ::xrGetInstanceProperties(instance, instanceProperties);
  }
  XrResult xrPollEvent(XrInstance instance,
                       XrEventDataBuffer *eventData) const {
    return ::xrPollEvent(instance, eventData);
  }
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) const {
    return ::xrResultToString(instance, value, buffer);
  }
  XrResult
  xrStructureTypeToString(XrInstance instance, XrStructureType value,
                          char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) const {
    return ::xrStructureTypeToString(instance, value, buffer);
  }
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) const {
    return ::xrGetSystem(instance, getInfo, systemId);
  }
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) const {
    return ::xrGetSystemProperties(instance, systemId, properties);
  }
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) const {
    return ::xrEnumerateEnvironmentBlendModes(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) const {
    return ::xrCreateSession(instance, createInfo, session);
  }
  XrResult xrDestroySession(XrSession session) const {
    return ::xrDestroySession(session);
  }
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) const {
    return ::xrEnumerateReferenceSpaces(session, spaceCapacityInput,
                                        spaceCountOutput, spaces);
  }
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) const {
    return ::xrCreateReferenceSpace(session, createInfo, space);
  }
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) const {
    return ::xrGetReferenceSpaceBoundsRect(session, referenceSpaceType, bounds);
  }
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) const {
    return ::xrCreateActionSpace(session, createInfo, space);
  }
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) const {
    return ::xrLocateSpace(space, baseSpace, time, location);
  }
  XrResult xrDestroySpace(XrSpace space) const {
    return ::xrDestroySpace(space);
  }
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) const {
    return ::xrEnumerateViewConfigurations(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) const {
    return ::xrGetViewConfigurationProperties(
        instance, systemId, viewConfigurationType, configurationProperties);
  }
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) const {
    return ::xrEnumerateViewConfigurationViews(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) const {
    return ::xrEnumerateSwapchainFormats(session, formatCapacityInput,
                                         formatCountOutput, formats);
  }
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) const {
    return ::xrCreateSwapchain(session, createInfo, swapchain);
  }
  XrResult xrDestroySwapchain(XrSwapchain swapchain) const {
    return ::xrDestroySwapchain(swapchain);
  }
  XrResult
  xrEnumerateSwapchainImages(XrSwapchain swapchain, uint32_t imageCapacityInput,
                             uint32_t *imageCountOutput,
                             XrSwapchainImageBaseHeader *images) const {
    return ::xrEnumerateSwapchainImages(swapchain, imageCapacityInput,
                                        imageCountOutput, images);
  }
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) const {
    return ::xrAcquireSwapchainImage(swapchain, acquireInfo, index);
  }
  XrResult
  xrWaitSwapchainImage(XrSwapchain swapchain,
                       const XrSwapchainImageWaitInfo *waitInfo) const {
    return ::xrWaitSwapchainImage(swapchain, waitInfo);
  }
  XrResult xrReleaseSwapchainImage(
      XrSwapchain swapchain,
      const XrSwapchainImageReleaseInfo *releaseInfo) const {
    return ::xrReleaseSwapchainImage(swapchain, releaseInfo);
  }
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) const {
    return ::xrBeginSession(session, beginInfo);
  }
  XrResult xrEndSession(XrSession session) const {
    return ::xrEndSession(session);
  }
  XrResult xrRequestExitSession(XrSession session) const {
    return ::xrRequestExitSession(session);
  }
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) const {
    return ::xrWaitFrame(session, frameWaitInfo, frameState);
  }
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) const {
    return ::xrBeginFrame(session, frameBeginInfo);
  }
  XrResult xrEndFrame(XrSession session,
                      const XrFrameEndInfo *frameEndInfo) const {
    return ::xrEndFrame(session, frameEndInfo);
  }
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) const {
    return ::xrLocateViews(session, viewLocateInfo, viewState,
                           viewCapacityInput, viewCountOutput, views);
  }
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) const {
    return ::xrStringToPath(instance, pathString, path);
  }
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) const {
    return ::xrPathToString(instance, path, bufferCapacityInput,
                            bufferCountOutput, buffer);
  }
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) const {
    return ::xrCreateActionSet(instance, createInfo, actionSet);
  }
  XrResult xrDestroyActionSet(XrActionSet actionSet) const {
    return ::xrDestroyActionSet(actionSet);
  }
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) const {
    return ::xrCreateAction(actionSet, createInfo, action);
  }
  XrResult xrDestroyAction(XrAction action) const {
    return ::xrDestroyAction(action);
  }
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) const {
    return ::xrSuggestInteractionProfileBindings(instance, suggestedBindings);
  }
  XrResult xrAttachSessionActionSets(
      XrSession session,
      const XrSessionActionSetsAttachInfo *attachInfo) const {
    return ::xrAttachSessionActionSets(session, attachInfo);
  }
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) const {
    return ::xrGetCurrentInteractionProfile(session, topLevelUserPath,
                                            interactionProfile);
  }
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) const {
    return ::xrGetActionStateBoolean(session, getInfo, state);
  }
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) const {
    return ::xrGetActionStateFloat(session, getInfo, state);
  }
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) const {
    return ::xrGetActionStateVector2f(session, getInfo, state);
  }
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) const {
    return ::xrGetActionStatePose(session, getInfo, state);
  }
  XrResult xrSyncActions(XrSession session,
                         const XrActionsSyncInfo *syncInfo) const {
    return ::xrSyncActions(session, syncInfo);
  }
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) const {
    return ::xrEnumerateBoundSourcesForAction(session, enumerateInfo,
                                              sourceCapacityInput,
                                              sourceCountOutput, sources);
  }
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput,
      char *buffer) const {
    return ::xrGetInputSourceLocalizedName(
        session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);
  }
  XrResult
  xrApplyHapticFeedback(XrSession session,
                        const XrHapticActionInfo *hapticActionInfo,
                        const XrHapticBaseHeader *hapticFeedback) const {
    return ::xrApplyHapticFeedback(session, hapticActionInfo, hapticFeedback);
  }
  XrResult
  xrStopHapticFeedback(XrSession session,
                       const XrHapticActionInfo *hapticActionInfo) const {
    return ::xrStopHapticFeedback(session, hapticActionInfo);
  }
  //! @}
};

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

template <typename FlagBitsType> struct FlagTraits {
  enum { allFlags = 0 };
};

template <typename BitType, typename MaskType = XrFlags64> class Flags {
public:
  OPENXR_HPP_CONSTEXPR Flags() : m_mask(0) {}

  Flags(BitType bit) : m_mask(static_cast<MaskType>(bit)) {}

  Flags(Flags<BitType> const &rhs) : m_mask(rhs.m_mask) {}

  explicit Flags(MaskType flags) : m_mask(flags) {}

  Flags<BitType> &operator=(Flags<BitType> const &rhs) {
    m_mask = rhs.m_mask;
    return *this;
  }

  Flags<BitType> &operator|=(Flags<BitType> const &rhs) {
    m_mask |= rhs.m_mask;
    return *this;
  }

  Flags<BitType> &operator&=(Flags<BitType> const &rhs) {
    m_mask &= rhs.m_mask;
    return *this;
  }

  Flags<BitType> &operator^=(Flags<BitType> const &rhs) {
    m_mask ^= rhs.m_mask;
    return *this;
  }

  Flags<BitType> operator|(Flags<BitType> const &rhs) const {
    Flags<BitType> result(*this);
    result |= rhs;
    return result;
  }

  Flags<BitType> operator&(Flags<BitType> const &rhs) const {
    Flags<BitType> result(*this);
    result &= rhs;
    return result;
  }

  Flags<BitType> operator^(Flags<BitType> const &rhs) const {
    Flags<BitType> result(*this);
    result ^= rhs;
    return result;
  }

  bool operator!() const { return !m_mask; }

  Flags<BitType> operator~() const {
    Flags<BitType> result(*this);
    result.m_mask ^= FlagTraits<BitType>::allFlags;
    return result;
  }

  bool operator==(Flags<BitType> const &rhs) const {
    return m_mask == rhs.m_mask;
  }

  bool operator!=(Flags<BitType> const &rhs) const {
    return m_mask != rhs.m_mask;
  }

  explicit operator bool() const { return !!m_mask; }

  explicit operator MaskType() const { return m_mask; }

private:
  MaskType m_mask;
};

template <typename BitType>
Flags<BitType> operator|(BitType bit, Flags<BitType> const &flags) {
  return flags | bit;
}

template <typename BitType>
Flags<BitType> operator&(BitType bit, Flags<BitType> const &flags) {
  return flags & bit;
}

template <typename BitType>
Flags<BitType> operator^(BitType bit, Flags<BitType> const &flags) {
  return flags ^ bit;
}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {

template <typename Type, typename Dispatch> class UniqueHandleTraits;

} // namespace traits

namespace impl {

// Used when returning unique handles.
template <typename T>
using RemoveRefConst =
    typename std::remove_const<typename std::remove_reference<T>::type>::type;
} // namespace impl

/*!
 * Template class for holding a handle with unique ownership, much like
 * unique_ptr.
 *
 * Note that this does not keep track of children or parents, though OpenXR
 * specifies that destruction of a handle also destroys its children
 * automatically.
 */
template <typename Type, typename Dispatch>
class UniqueHandle
    : public traits::UniqueHandleTraits<Type, Dispatch>::deleter {
private:
  using Deleter = typename traits::UniqueHandleTraits<Type, Dispatch>::deleter;

public:
  explicit UniqueHandle(Type const &value = Type(),
                        Deleter const &deleter = Deleter())
      : Deleter(deleter), m_value(value) {}

  UniqueHandle(UniqueHandle const &) = delete;

  UniqueHandle(UniqueHandle &&other)
      : Deleter(std::move(static_cast<Deleter &>(other))),
        m_value(other.release()) {}

  ~UniqueHandle() {
    if (m_value)
      this->destroy(m_value);
  }

  UniqueHandle &operator=(UniqueHandle const &) = delete;

  UniqueHandle &operator=(UniqueHandle &&other) {
    reset(other.release());
    *static_cast<Deleter *>(this) = std::move(static_cast<Deleter &>(other));
    return *this;
  }

  explicit operator bool() const { return m_value.operator bool(); }

  Type const *operator->() const { return &m_value; }

  Type *operator->() { return &m_value; }

  Type const &operator*() const { return m_value; }

  Type &operator*() { return m_value; }

  const Type &get() const { return m_value; }

  Type &get() { return m_value; }

  void reset(Type const &value = Type()) {
    if (m_value != value) {
      if (m_value)
        this->destroy(m_value);
      m_value = value;
    }
  }

  typename Type::RawHandleType *put() {
    reset();
    return m_value.put();
  }

  Type release() {
    Type value = m_value;
    m_value = nullptr;
    return value;
  }

  void swap(UniqueHandle<Type, Dispatch> &rhs) {
    std::swap(m_value, rhs.m_value);
    std::swap(static_cast<Deleter &>(*this), static_cast<Deleter &>(rhs));
  }

private:
  Type m_value;
};
template <typename Type, typename Dispatch>
class UniqueHandle<Type, Dispatch &> : public UniqueHandle<Type, Dispatch> {};

template <typename Type, typename Dispatch>
class UniqueHandle<Type, Dispatch const> : public UniqueHandle<Type, Dispatch> {
};

//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_INLINE void swap(UniqueHandle<Type, Dispatch> &lhs,
                            UniqueHandle<Type, Dispatch> &rhs) {
  lhs.swap(rhs);
}
#endif

template <typename Dispatch> class ObjectDestroy {
public:
  ObjectDestroy(Dispatch const &dispatch = Dispatch())
      : m_dispatch(&dispatch) {}

protected:
  template <typename T> void destroy(T t) { t.destroy(*m_dispatch); }

private:
  Dispatch const *m_dispatch;
};
} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {
/*!
 * @defgroup enums Enumerations
 * @brief C++ enum classes corresponding to OpenXR C enumerations, plus
 * associated utility functions.
 *
 * All enumerations have three utility functions defined:
 *
 * - get() - returns the raw C enum value
 * - to_string_literal() - returns a const char* containing the C++ name
 * - to_string() - wraps to_string_literal(), returning a std::string
 *
 * @{
 */

//! @brief Enum class associated with XrResult
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrResult>
enum class Result : int32_t {

  Success = XR_SUCCESS,

  TimeoutExpired = XR_TIMEOUT_EXPIRED,

  SessionLossPending = XR_SESSION_LOSS_PENDING,

  EventUnavailable = XR_EVENT_UNAVAILABLE,

  SpaceBoundsUnavailable = XR_SPACE_BOUNDS_UNAVAILABLE,

  SessionNotFocused = XR_SESSION_NOT_FOCUSED,

  FrameDiscarded = XR_FRAME_DISCARDED,

  ErrorValidationFailure = XR_ERROR_VALIDATION_FAILURE,

  ErrorRuntimeFailure = XR_ERROR_RUNTIME_FAILURE,

  ErrorOutOfMemory = XR_ERROR_OUT_OF_MEMORY,

  ErrorApiVersionUnsupported = XR_ERROR_API_VERSION_UNSUPPORTED,

  ErrorInitializationFailed = XR_ERROR_INITIALIZATION_FAILED,

  ErrorFunctionUnsupported = XR_ERROR_FUNCTION_UNSUPPORTED,

  ErrorFeatureUnsupported = XR_ERROR_FEATURE_UNSUPPORTED,

  ErrorExtensionNotPresent = XR_ERROR_EXTENSION_NOT_PRESENT,

  ErrorLimitReached = XR_ERROR_LIMIT_REACHED,

  ErrorSizeInsufficient = XR_ERROR_SIZE_INSUFFICIENT,

  ErrorHandleInvalid = XR_ERROR_HANDLE_INVALID,

  ErrorInstanceLost = XR_ERROR_INSTANCE_LOST,

  ErrorSessionRunning = XR_ERROR_SESSION_RUNNING,

  ErrorSessionNotRunning = XR_ERROR_SESSION_NOT_RUNNING,

  ErrorSessionLost = XR_ERROR_SESSION_LOST,

  ErrorSystemInvalid = XR_ERROR_SYSTEM_INVALID,

  ErrorPathInvalid = XR_ERROR_PATH_INVALID,

  ErrorPathCountExceeded = XR_ERROR_PATH_COUNT_EXCEEDED,

  ErrorPathFormatInvalid = XR_ERROR_PATH_FORMAT_INVALID,

  ErrorPathUnsupported = XR_ERROR_PATH_UNSUPPORTED,

  ErrorLayerInvalid = XR_ERROR_LAYER_INVALID,

  ErrorLayerLimitExceeded = XR_ERROR_LAYER_LIMIT_EXCEEDED,

  ErrorSwapchainRectInvalid = XR_ERROR_SWAPCHAIN_RECT_INVALID,

  ErrorSwapchainFormatUnsupported = XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED,

  ErrorActionTypeMismatch = XR_ERROR_ACTION_TYPE_MISMATCH,

  ErrorSessionNotReady = XR_ERROR_SESSION_NOT_READY,

  ErrorSessionNotStopping = XR_ERROR_SESSION_NOT_STOPPING,

  ErrorTimeInvalid = XR_ERROR_TIME_INVALID,

  ErrorReferenceSpaceUnsupported = XR_ERROR_REFERENCE_SPACE_UNSUPPORTED,

  ErrorFileAccessError = XR_ERROR_FILE_ACCESS_ERROR,

  ErrorFileContentsInvalid = XR_ERROR_FILE_CONTENTS_INVALID,

  ErrorFormFactorUnsupported = XR_ERROR_FORM_FACTOR_UNSUPPORTED,

  ErrorFormFactorUnavailable = XR_ERROR_FORM_FACTOR_UNAVAILABLE,

  ErrorApiLayerNotPresent = XR_ERROR_API_LAYER_NOT_PRESENT,

  ErrorCallOrderInvalid = XR_ERROR_CALL_ORDER_INVALID,

  ErrorGraphicsDeviceInvalid = XR_ERROR_GRAPHICS_DEVICE_INVALID,

  ErrorPoseInvalid = XR_ERROR_POSE_INVALID,

  ErrorIndexOutOfRange = XR_ERROR_INDEX_OUT_OF_RANGE,

  ErrorViewConfigurationTypeUnsupported =
      XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED,

  ErrorEnvironmentBlendModeUnsupported =
      XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED,

  ErrorNameDuplicated = XR_ERROR_NAME_DUPLICATED,

  ErrorNameInvalid = XR_ERROR_NAME_INVALID,

  ErrorActionsetNotAttached = XR_ERROR_ACTIONSET_NOT_ATTACHED,

  ErrorActionsetsAlreadyAttached = XR_ERROR_ACTIONSETS_ALREADY_ATTACHED,

  ErrorLocalizedNameDuplicated = XR_ERROR_LOCALIZED_NAME_DUPLICATED,

  ErrorLocalizedNameInvalid = XR_ERROR_LOCALIZED_NAME_INVALID,

  ErrorAndroidThreadSettingsIdInvalidKHR =
      XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR,

  ErrorAndroidThreadSettingsFailureKHR =
      XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR,

  ErrorCreateSpatialAnchorFailedMSFT =
      XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT,

};

//! @brief Free function for retrieving the raw XrResult value from a Result
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrResult get(Result const &v) {
  return static_cast<XrResult>(v);
}

//! @brief Free function for retrieving the string name of a Result value as a
//! const char *
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(Result value) {
  switch (value) {

  case Result::Success:
    return "Success";

  case Result::TimeoutExpired:
    return "TimeoutExpired";

  case Result::SessionLossPending:
    return "SessionLossPending";

  case Result::EventUnavailable:
    return "EventUnavailable";

  case Result::SpaceBoundsUnavailable:
    return "SpaceBoundsUnavailable";

  case Result::SessionNotFocused:
    return "SessionNotFocused";

  case Result::FrameDiscarded:
    return "FrameDiscarded";

  case Result::ErrorValidationFailure:
    return "ErrorValidationFailure";

  case Result::ErrorRuntimeFailure:
    return "ErrorRuntimeFailure";

  case Result::ErrorOutOfMemory:
    return "ErrorOutOfMemory";

  case Result::ErrorApiVersionUnsupported:
    return "ErrorApiVersionUnsupported";

  case Result::ErrorInitializationFailed:
    return "ErrorInitializationFailed";

  case Result::ErrorFunctionUnsupported:
    return "ErrorFunctionUnsupported";

  case Result::ErrorFeatureUnsupported:
    return "ErrorFeatureUnsupported";

  case Result::ErrorExtensionNotPresent:
    return "ErrorExtensionNotPresent";

  case Result::ErrorLimitReached:
    return "ErrorLimitReached";

  case Result::ErrorSizeInsufficient:
    return "ErrorSizeInsufficient";

  case Result::ErrorHandleInvalid:
    return "ErrorHandleInvalid";

  case Result::ErrorInstanceLost:
    return "ErrorInstanceLost";

  case Result::ErrorSessionRunning:
    return "ErrorSessionRunning";

  case Result::ErrorSessionNotRunning:
    return "ErrorSessionNotRunning";

  case Result::ErrorSessionLost:
    return "ErrorSessionLost";

  case Result::ErrorSystemInvalid:
    return "ErrorSystemInvalid";

  case Result::ErrorPathInvalid:
    return "ErrorPathInvalid";

  case Result::ErrorPathCountExceeded:
    return "ErrorPathCountExceeded";

  case Result::ErrorPathFormatInvalid:
    return "ErrorPathFormatInvalid";

  case Result::ErrorPathUnsupported:
    return "ErrorPathUnsupported";

  case Result::ErrorLayerInvalid:
    return "ErrorLayerInvalid";

  case Result::ErrorLayerLimitExceeded:
    return "ErrorLayerLimitExceeded";

  case Result::ErrorSwapchainRectInvalid:
    return "ErrorSwapchainRectInvalid";

  case Result::ErrorSwapchainFormatUnsupported:
    return "ErrorSwapchainFormatUnsupported";

  case Result::ErrorActionTypeMismatch:
    return "ErrorActionTypeMismatch";

  case Result::ErrorSessionNotReady:
    return "ErrorSessionNotReady";

  case Result::ErrorSessionNotStopping:
    return "ErrorSessionNotStopping";

  case Result::ErrorTimeInvalid:
    return "ErrorTimeInvalid";

  case Result::ErrorReferenceSpaceUnsupported:
    return "ErrorReferenceSpaceUnsupported";

  case Result::ErrorFileAccessError:
    return "ErrorFileAccessError";

  case Result::ErrorFileContentsInvalid:
    return "ErrorFileContentsInvalid";

  case Result::ErrorFormFactorUnsupported:
    return "ErrorFormFactorUnsupported";

  case Result::ErrorFormFactorUnavailable:
    return "ErrorFormFactorUnavailable";

  case Result::ErrorApiLayerNotPresent:
    return "ErrorApiLayerNotPresent";

  case Result::ErrorCallOrderInvalid:
    return "ErrorCallOrderInvalid";

  case Result::ErrorGraphicsDeviceInvalid:
    return "ErrorGraphicsDeviceInvalid";

  case Result::ErrorPoseInvalid:
    return "ErrorPoseInvalid";

  case Result::ErrorIndexOutOfRange:
    return "ErrorIndexOutOfRange";

  case Result::ErrorViewConfigurationTypeUnsupported:
    return "ErrorViewConfigurationTypeUnsupported";

  case Result::ErrorEnvironmentBlendModeUnsupported:
    return "ErrorEnvironmentBlendModeUnsupported";

  case Result::ErrorNameDuplicated:
    return "ErrorNameDuplicated";

  case Result::ErrorNameInvalid:
    return "ErrorNameInvalid";

  case Result::ErrorActionsetNotAttached:
    return "ErrorActionsetNotAttached";

  case Result::ErrorActionsetsAlreadyAttached:
    return "ErrorActionsetsAlreadyAttached";

  case Result::ErrorLocalizedNameDuplicated:
    return "ErrorLocalizedNameDuplicated";

  case Result::ErrorLocalizedNameInvalid:
    return "ErrorLocalizedNameInvalid";

  case Result::ErrorAndroidThreadSettingsIdInvalidKHR:
    return "ErrorAndroidThreadSettingsIdInvalidKHR";

  case Result::ErrorAndroidThreadSettingsFailureKHR:
    return "ErrorAndroidThreadSettingsFailureKHR";

  case Result::ErrorCreateSpatialAnchorFailedMSFT:
    return "ErrorCreateSpatialAnchorFailedMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a Result value as a
//! std::string
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(Result value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrStructureType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrStructureType>
enum class StructureType : uint32_t {

  Unknown = XR_TYPE_UNKNOWN,

  ApiLayerProperties = XR_TYPE_API_LAYER_PROPERTIES,

  ExtensionProperties = XR_TYPE_EXTENSION_PROPERTIES,

  InstanceCreateInfo = XR_TYPE_INSTANCE_CREATE_INFO,

  SystemGetInfo = XR_TYPE_SYSTEM_GET_INFO,

  SystemProperties = XR_TYPE_SYSTEM_PROPERTIES,

  ViewLocateInfo = XR_TYPE_VIEW_LOCATE_INFO,

  View = XR_TYPE_VIEW,

  SessionCreateInfo = XR_TYPE_SESSION_CREATE_INFO,

  SwapchainCreateInfo = XR_TYPE_SWAPCHAIN_CREATE_INFO,

  SessionBeginInfo = XR_TYPE_SESSION_BEGIN_INFO,

  ViewState = XR_TYPE_VIEW_STATE,

  FrameEndInfo = XR_TYPE_FRAME_END_INFO,

  HapticVibration = XR_TYPE_HAPTIC_VIBRATION,

  EventDataBuffer = XR_TYPE_EVENT_DATA_BUFFER,

  EventDataInstanceLossPending = XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING,

  EventDataSessionStateChanged = XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED,

  ActionStateBoolean = XR_TYPE_ACTION_STATE_BOOLEAN,

  ActionStateFloat = XR_TYPE_ACTION_STATE_FLOAT,

  ActionStateVector2F = XR_TYPE_ACTION_STATE_VECTOR2F,

  ActionStatePose = XR_TYPE_ACTION_STATE_POSE,

  ActionSetCreateInfo = XR_TYPE_ACTION_SET_CREATE_INFO,

  ActionCreateInfo = XR_TYPE_ACTION_CREATE_INFO,

  InstanceProperties = XR_TYPE_INSTANCE_PROPERTIES,

  FrameWaitInfo = XR_TYPE_FRAME_WAIT_INFO,

  CompositionLayerProjection = XR_TYPE_COMPOSITION_LAYER_PROJECTION,

  CompositionLayerQuad = XR_TYPE_COMPOSITION_LAYER_QUAD,

  ReferenceSpaceCreateInfo = XR_TYPE_REFERENCE_SPACE_CREATE_INFO,

  ActionSpaceCreateInfo = XR_TYPE_ACTION_SPACE_CREATE_INFO,

  EventDataReferenceSpaceChangePending =
      XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING,

  ViewConfigurationView = XR_TYPE_VIEW_CONFIGURATION_VIEW,

  SpaceLocation = XR_TYPE_SPACE_LOCATION,

  SpaceVelocity = XR_TYPE_SPACE_VELOCITY,

  FrameState = XR_TYPE_FRAME_STATE,

  ViewConfigurationProperties = XR_TYPE_VIEW_CONFIGURATION_PROPERTIES,

  FrameBeginInfo = XR_TYPE_FRAME_BEGIN_INFO,

  CompositionLayerProjectionView = XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,

  EventDataEventsLost = XR_TYPE_EVENT_DATA_EVENTS_LOST,

  InteractionProfileSuggestedBinding =
      XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING,

  EventDataInteractionProfileChanged =
      XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED,

  InteractionProfileState = XR_TYPE_INTERACTION_PROFILE_STATE,

  SwapchainImageAcquireInfo = XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO,

  SwapchainImageWaitInfo = XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO,

  SwapchainImageReleaseInfo = XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO,

  ActionStateGetInfo = XR_TYPE_ACTION_STATE_GET_INFO,

  HapticActionInfo = XR_TYPE_HAPTIC_ACTION_INFO,

  SessionActionSetsAttachInfo = XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO,

  ActionsSyncInfo = XR_TYPE_ACTIONS_SYNC_INFO,

  BoundSourcesForActionEnumerateInfo =
      XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO,

  InputSourceLocalizedNameGetInfo =
      XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO,

  CompositionLayerCubeKHR = XR_TYPE_COMPOSITION_LAYER_CUBE_KHR,

  InstanceCreateInfoAndroidKHR = XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR,

  CompositionLayerDepthInfoKHR = XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR,

  VulkanSwapchainFormatListCreateInfoKHR =
      XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR,

  EventDataPerfSettingsEXT = XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT,

  CompositionLayerCylinderKHR = XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR,

  CompositionLayerEquirectKHR = XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR,

  DebugUtilsObjectNameInfoEXT = XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,

  DebugUtilsMessengerCallbackDataEXT =
      XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT,

  DebugUtilsMessengerCreateInfoEXT =
      XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,

  DebugUtilsLabelEXT = XR_TYPE_DEBUG_UTILS_LABEL_EXT,

  GraphicsBindingOpenglWin32KHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR,

  GraphicsBindingOpenglXlibKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR,

  GraphicsBindingOpenglXcbKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR,

  GraphicsBindingOpenglWaylandKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR,

  SwapchainImageOpenglKHR = XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR,

  GraphicsRequirementsOpenglKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR,

  GraphicsBindingOpenglEsAndroidKHR =
      XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR,

  SwapchainImageOpenglEsKHR = XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR,

  GraphicsRequirementsOpenglEsKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR,

  GraphicsBindingVulkanKHR = XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR,

  SwapchainImageVulkanKHR = XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR,

  GraphicsRequirementsVulkanKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR,

  GraphicsBindingD3D11KHR = XR_TYPE_GRAPHICS_BINDING_D3D11_KHR,

  SwapchainImageD3D11KHR = XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR,

  GraphicsRequirementsD3D11KHR = XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR,

  GraphicsBindingD3D12KHR = XR_TYPE_GRAPHICS_BINDING_D3D12_KHR,

  SwapchainImageD3D12KHR = XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR,

  GraphicsRequirementsD3D12KHR = XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR,

  VisibilityMaskKHR = XR_TYPE_VISIBILITY_MASK_KHR,

  EventDataVisibilityMaskChangedKHR =
      XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR,

  SpatialAnchorCreateInfoMSFT = XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT,

  SpatialAnchorSpaceCreateInfoMSFT =
      XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT,

};

//! @brief Free function for retrieving the raw XrStructureType value from a
//! StructureType
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrStructureType
get(StructureType const &v) {
  return static_cast<XrStructureType>(v);
}

//! @brief Free function for retrieving the string name of a StructureType value
//! as a const char *
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(StructureType value) {
  switch (value) {

  case StructureType::Unknown:
    return "Unknown";

  case StructureType::ApiLayerProperties:
    return "ApiLayerProperties";

  case StructureType::ExtensionProperties:
    return "ExtensionProperties";

  case StructureType::InstanceCreateInfo:
    return "InstanceCreateInfo";

  case StructureType::SystemGetInfo:
    return "SystemGetInfo";

  case StructureType::SystemProperties:
    return "SystemProperties";

  case StructureType::ViewLocateInfo:
    return "ViewLocateInfo";

  case StructureType::View:
    return "View";

  case StructureType::SessionCreateInfo:
    return "SessionCreateInfo";

  case StructureType::SwapchainCreateInfo:
    return "SwapchainCreateInfo";

  case StructureType::SessionBeginInfo:
    return "SessionBeginInfo";

  case StructureType::ViewState:
    return "ViewState";

  case StructureType::FrameEndInfo:
    return "FrameEndInfo";

  case StructureType::HapticVibration:
    return "HapticVibration";

  case StructureType::EventDataBuffer:
    return "EventDataBuffer";

  case StructureType::EventDataInstanceLossPending:
    return "EventDataInstanceLossPending";

  case StructureType::EventDataSessionStateChanged:
    return "EventDataSessionStateChanged";

  case StructureType::ActionStateBoolean:
    return "ActionStateBoolean";

  case StructureType::ActionStateFloat:
    return "ActionStateFloat";

  case StructureType::ActionStateVector2F:
    return "ActionStateVector2F";

  case StructureType::ActionStatePose:
    return "ActionStatePose";

  case StructureType::ActionSetCreateInfo:
    return "ActionSetCreateInfo";

  case StructureType::ActionCreateInfo:
    return "ActionCreateInfo";

  case StructureType::InstanceProperties:
    return "InstanceProperties";

  case StructureType::FrameWaitInfo:
    return "FrameWaitInfo";

  case StructureType::CompositionLayerProjection:
    return "CompositionLayerProjection";

  case StructureType::CompositionLayerQuad:
    return "CompositionLayerQuad";

  case StructureType::ReferenceSpaceCreateInfo:
    return "ReferenceSpaceCreateInfo";

  case StructureType::ActionSpaceCreateInfo:
    return "ActionSpaceCreateInfo";

  case StructureType::EventDataReferenceSpaceChangePending:
    return "EventDataReferenceSpaceChangePending";

  case StructureType::ViewConfigurationView:
    return "ViewConfigurationView";

  case StructureType::SpaceLocation:
    return "SpaceLocation";

  case StructureType::SpaceVelocity:
    return "SpaceVelocity";

  case StructureType::FrameState:
    return "FrameState";

  case StructureType::ViewConfigurationProperties:
    return "ViewConfigurationProperties";

  case StructureType::FrameBeginInfo:
    return "FrameBeginInfo";

  case StructureType::CompositionLayerProjectionView:
    return "CompositionLayerProjectionView";

  case StructureType::EventDataEventsLost:
    return "EventDataEventsLost";

  case StructureType::InteractionProfileSuggestedBinding:
    return "InteractionProfileSuggestedBinding";

  case StructureType::EventDataInteractionProfileChanged:
    return "EventDataInteractionProfileChanged";

  case StructureType::InteractionProfileState:
    return "InteractionProfileState";

  case StructureType::SwapchainImageAcquireInfo:
    return "SwapchainImageAcquireInfo";

  case StructureType::SwapchainImageWaitInfo:
    return "SwapchainImageWaitInfo";

  case StructureType::SwapchainImageReleaseInfo:
    return "SwapchainImageReleaseInfo";

  case StructureType::ActionStateGetInfo:
    return "ActionStateGetInfo";

  case StructureType::HapticActionInfo:
    return "HapticActionInfo";

  case StructureType::SessionActionSetsAttachInfo:
    return "SessionActionSetsAttachInfo";

  case StructureType::ActionsSyncInfo:
    return "ActionsSyncInfo";

  case StructureType::BoundSourcesForActionEnumerateInfo:
    return "BoundSourcesForActionEnumerateInfo";

  case StructureType::InputSourceLocalizedNameGetInfo:
    return "InputSourceLocalizedNameGetInfo";

  case StructureType::CompositionLayerCubeKHR:
    return "CompositionLayerCubeKHR";

  case StructureType::InstanceCreateInfoAndroidKHR:
    return "InstanceCreateInfoAndroidKHR";

  case StructureType::CompositionLayerDepthInfoKHR:
    return "CompositionLayerDepthInfoKHR";

  case StructureType::VulkanSwapchainFormatListCreateInfoKHR:
    return "VulkanSwapchainFormatListCreateInfoKHR";

  case StructureType::EventDataPerfSettingsEXT:
    return "EventDataPerfSettingsEXT";

  case StructureType::CompositionLayerCylinderKHR:
    return "CompositionLayerCylinderKHR";

  case StructureType::CompositionLayerEquirectKHR:
    return "CompositionLayerEquirectKHR";

  case StructureType::DebugUtilsObjectNameInfoEXT:
    return "DebugUtilsObjectNameInfoEXT";

  case StructureType::DebugUtilsMessengerCallbackDataEXT:
    return "DebugUtilsMessengerCallbackDataEXT";

  case StructureType::DebugUtilsMessengerCreateInfoEXT:
    return "DebugUtilsMessengerCreateInfoEXT";

  case StructureType::DebugUtilsLabelEXT:
    return "DebugUtilsLabelEXT";

  case StructureType::GraphicsBindingOpenglWin32KHR:
    return "GraphicsBindingOpenglWin32KHR";

  case StructureType::GraphicsBindingOpenglXlibKHR:
    return "GraphicsBindingOpenglXlibKHR";

  case StructureType::GraphicsBindingOpenglXcbKHR:
    return "GraphicsBindingOpenglXcbKHR";

  case StructureType::GraphicsBindingOpenglWaylandKHR:
    return "GraphicsBindingOpenglWaylandKHR";

  case StructureType::SwapchainImageOpenglKHR:
    return "SwapchainImageOpenglKHR";

  case StructureType::GraphicsRequirementsOpenglKHR:
    return "GraphicsRequirementsOpenglKHR";

  case StructureType::GraphicsBindingOpenglEsAndroidKHR:
    return "GraphicsBindingOpenglEsAndroidKHR";

  case StructureType::SwapchainImageOpenglEsKHR:
    return "SwapchainImageOpenglEsKHR";

  case StructureType::GraphicsRequirementsOpenglEsKHR:
    return "GraphicsRequirementsOpenglEsKHR";

  case StructureType::GraphicsBindingVulkanKHR:
    return "GraphicsBindingVulkanKHR";

  case StructureType::SwapchainImageVulkanKHR:
    return "SwapchainImageVulkanKHR";

  case StructureType::GraphicsRequirementsVulkanKHR:
    return "GraphicsRequirementsVulkanKHR";

  case StructureType::GraphicsBindingD3D11KHR:
    return "GraphicsBindingD3D11KHR";

  case StructureType::SwapchainImageD3D11KHR:
    return "SwapchainImageD3D11KHR";

  case StructureType::GraphicsRequirementsD3D11KHR:
    return "GraphicsRequirementsD3D11KHR";

  case StructureType::GraphicsBindingD3D12KHR:
    return "GraphicsBindingD3D12KHR";

  case StructureType::SwapchainImageD3D12KHR:
    return "SwapchainImageD3D12KHR";

  case StructureType::GraphicsRequirementsD3D12KHR:
    return "GraphicsRequirementsD3D12KHR";

  case StructureType::VisibilityMaskKHR:
    return "VisibilityMaskKHR";

  case StructureType::EventDataVisibilityMaskChangedKHR:
    return "EventDataVisibilityMaskChangedKHR";

  case StructureType::SpatialAnchorCreateInfoMSFT:
    return "SpatialAnchorCreateInfoMSFT";

  case StructureType::SpatialAnchorSpaceCreateInfoMSFT:
    return "SpatialAnchorSpaceCreateInfoMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a StructureType value
//! as a std::string
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(StructureType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrFormFactor
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrFormFactor>
enum class FormFactor : uint32_t {

  HeadMountedDisplay = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY,

  HandheldDisplay = XR_FORM_FACTOR_HANDHELD_DISPLAY,

};

//! @brief Free function for retrieving the raw XrFormFactor value from a
//! FormFactor
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrFormFactor get(FormFactor const &v) {
  return static_cast<XrFormFactor>(v);
}

//! @brief Free function for retrieving the string name of a FormFactor value as
//! a const char *
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(FormFactor value) {
  switch (value) {

  case FormFactor::HeadMountedDisplay:
    return "HeadMountedDisplay";

  case FormFactor::HandheldDisplay:
    return "HandheldDisplay";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a FormFactor value as
//! a std::string
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(FormFactor value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrViewConfigurationType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrViewConfigurationType>
enum class ViewConfigurationType : uint32_t {

  PrimaryMono = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_MONO,

  PrimaryStereo = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO,

  PrimaryQuadVARJO = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_QUAD_VARJO,

};

//! @brief Free function for retrieving the raw XrViewConfigurationType value
//! from a ViewConfigurationType
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrViewConfigurationType
get(ViewConfigurationType const &v) {
  return static_cast<XrViewConfigurationType>(v);
}

//! @brief Free function for retrieving the string name of a
//! ViewConfigurationType value as a const char *
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ViewConfigurationType value) {
  switch (value) {

  case ViewConfigurationType::PrimaryMono:
    return "PrimaryMono";

  case ViewConfigurationType::PrimaryStereo:
    return "PrimaryStereo";

  case ViewConfigurationType::PrimaryQuadVARJO:
    return "PrimaryQuadVARJO";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! ViewConfigurationType value as a std::string
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ViewConfigurationType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrEnvironmentBlendMode
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrEnvironmentBlendMode>
enum class EnvironmentBlendMode : uint32_t {

  Opaque = XR_ENVIRONMENT_BLEND_MODE_OPAQUE,

  Additive = XR_ENVIRONMENT_BLEND_MODE_ADDITIVE,

  AlphaBlend = XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND,

};

//! @brief Free function for retrieving the raw XrEnvironmentBlendMode value
//! from a EnvironmentBlendMode
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrEnvironmentBlendMode
get(EnvironmentBlendMode const &v) {
  return static_cast<XrEnvironmentBlendMode>(v);
}

//! @brief Free function for retrieving the string name of a
//! EnvironmentBlendMode value as a const char *
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(EnvironmentBlendMode value) {
  switch (value) {

  case EnvironmentBlendMode::Opaque:
    return "Opaque";

  case EnvironmentBlendMode::Additive:
    return "Additive";

  case EnvironmentBlendMode::AlphaBlend:
    return "AlphaBlend";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! EnvironmentBlendMode value as a std::string
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(EnvironmentBlendMode value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrReferenceSpaceType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrReferenceSpaceType>
enum class ReferenceSpaceType : uint32_t {

  View = XR_REFERENCE_SPACE_TYPE_VIEW,

  Local = XR_REFERENCE_SPACE_TYPE_LOCAL,

  Stage = XR_REFERENCE_SPACE_TYPE_STAGE,

  UnboundedMSFT = XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT,

};

//! @brief Free function for retrieving the raw XrReferenceSpaceType value from
//! a ReferenceSpaceType
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrReferenceSpaceType
get(ReferenceSpaceType const &v) {
  return static_cast<XrReferenceSpaceType>(v);
}

//! @brief Free function for retrieving the string name of a ReferenceSpaceType
//! value as a const char *
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ReferenceSpaceType value) {
  switch (value) {

  case ReferenceSpaceType::View:
    return "View";

  case ReferenceSpaceType::Local:
    return "Local";

  case ReferenceSpaceType::Stage:
    return "Stage";

  case ReferenceSpaceType::UnboundedMSFT:
    return "UnboundedMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ReferenceSpaceType
//! value as a std::string
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ReferenceSpaceType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrActionType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrActionType>
enum class ActionType : uint32_t {

  BooleanInput = XR_ACTION_TYPE_BOOLEAN_INPUT,

  FloatInput = XR_ACTION_TYPE_FLOAT_INPUT,

  Vector2FInput = XR_ACTION_TYPE_VECTOR2F_INPUT,

  PoseInput = XR_ACTION_TYPE_POSE_INPUT,

  VibrationOutput = XR_ACTION_TYPE_VIBRATION_OUTPUT,

};

//! @brief Free function for retrieving the raw XrActionType value from a
//! ActionType
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrActionType get(ActionType const &v) {
  return static_cast<XrActionType>(v);
}

//! @brief Free function for retrieving the string name of a ActionType value as
//! a const char *
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ActionType value) {
  switch (value) {

  case ActionType::BooleanInput:
    return "BooleanInput";

  case ActionType::FloatInput:
    return "FloatInput";

  case ActionType::Vector2FInput:
    return "Vector2FInput";

  case ActionType::PoseInput:
    return "PoseInput";

  case ActionType::VibrationOutput:
    return "VibrationOutput";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ActionType value as
//! a std::string
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ActionType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrEyeVisibility
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrEyeVisibility>
enum class EyeVisibility : uint32_t {

  Both = XR_EYE_VISIBILITY_BOTH,

  Left = XR_EYE_VISIBILITY_LEFT,

  Right = XR_EYE_VISIBILITY_RIGHT,

};

//! @brief Free function for retrieving the raw XrEyeVisibility value from a
//! EyeVisibility
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrEyeVisibility
get(EyeVisibility const &v) {
  return static_cast<XrEyeVisibility>(v);
}

//! @brief Free function for retrieving the string name of a EyeVisibility value
//! as a const char *
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(EyeVisibility value) {
  switch (value) {

  case EyeVisibility::Both:
    return "Both";

  case EyeVisibility::Left:
    return "Left";

  case EyeVisibility::Right:
    return "Right";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a EyeVisibility value
//! as a std::string
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(EyeVisibility value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrSessionState
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSessionState>
enum class SessionState : uint32_t {

  Unknown = XR_SESSION_STATE_UNKNOWN,

  Idle = XR_SESSION_STATE_IDLE,

  Ready = XR_SESSION_STATE_READY,

  Synchronized = XR_SESSION_STATE_SYNCHRONIZED,

  Visible = XR_SESSION_STATE_VISIBLE,

  Focused = XR_SESSION_STATE_FOCUSED,

  Stopping = XR_SESSION_STATE_STOPPING,

  LossPending = XR_SESSION_STATE_LOSS_PENDING,

  Exiting = XR_SESSION_STATE_EXITING,

};

//! @brief Free function for retrieving the raw XrSessionState value from a
//! SessionState
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrSessionState
get(SessionState const &v) {
  return static_cast<XrSessionState>(v);
}

//! @brief Free function for retrieving the string name of a SessionState value
//! as a const char *
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(SessionState value) {
  switch (value) {

  case SessionState::Unknown:
    return "Unknown";

  case SessionState::Idle:
    return "Idle";

  case SessionState::Ready:
    return "Ready";

  case SessionState::Synchronized:
    return "Synchronized";

  case SessionState::Visible:
    return "Visible";

  case SessionState::Focused:
    return "Focused";

  case SessionState::Stopping:
    return "Stopping";

  case SessionState::LossPending:
    return "LossPending";

  case SessionState::Exiting:
    return "Exiting";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a SessionState value
//! as a std::string
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(SessionState value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrObjectType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrObjectType>
enum class ObjectType : uint32_t {

  Unknown = XR_OBJECT_TYPE_UNKNOWN,

  Instance = XR_OBJECT_TYPE_INSTANCE,

  Session = XR_OBJECT_TYPE_SESSION,

  Swapchain = XR_OBJECT_TYPE_SWAPCHAIN,

  Space = XR_OBJECT_TYPE_SPACE,

  ActionSet = XR_OBJECT_TYPE_ACTION_SET,

  Action = XR_OBJECT_TYPE_ACTION,

  DebugUtilsMessengerEXT = XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT,

  SpatialAnchorMSFT = XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT,

};

//! @brief Free function for retrieving the raw XrObjectType value from a
//! ObjectType
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrObjectType get(ObjectType const &v) {
  return static_cast<XrObjectType>(v);
}

//! @brief Free function for retrieving the string name of a ObjectType value as
//! a const char *
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ObjectType value) {
  switch (value) {

  case ObjectType::Unknown:
    return "Unknown";

  case ObjectType::Instance:
    return "Instance";

  case ObjectType::Session:
    return "Session";

  case ObjectType::Swapchain:
    return "Swapchain";

  case ObjectType::Space:
    return "Space";

  case ObjectType::ActionSet:
    return "ActionSet";

  case ObjectType::Action:
    return "Action";

  case ObjectType::DebugUtilsMessengerEXT:
    return "DebugUtilsMessengerEXT";

  case ObjectType::SpatialAnchorMSFT:
    return "SpatialAnchorMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ObjectType value as
//! a std::string
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ObjectType value) {
  return {to_string_literal(value)};
}

#if defined(XR_USE_PLATFORM_ANDROID)
//! @brief Enum class associated with XrAndroidThreadTypeKHR
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrAndroidThreadTypeKHR>
enum class AndroidThreadTypeKHR : uint32_t {

  ApplicationMain = XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR,

  ApplicationWorker = XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR,

  RendererMain = XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR,

  RendererWorker = XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR,

};

//! @brief Free function for retrieving the raw XrAndroidThreadTypeKHR value
//! from a AndroidThreadTypeKHR
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrAndroidThreadTypeKHR
get(AndroidThreadTypeKHR const &v) {
  return static_cast<XrAndroidThreadTypeKHR>(v);
}

//! @brief Free function for retrieving the string name of a
//! AndroidThreadTypeKHR value as a const char *
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(AndroidThreadTypeKHR value) {
  switch (value) {

  case AndroidThreadTypeKHR::ApplicationMain:
    return "ApplicationMain";

  case AndroidThreadTypeKHR::ApplicationWorker:
    return "ApplicationWorker";

  case AndroidThreadTypeKHR::RendererMain:
    return "RendererMain";

  case AndroidThreadTypeKHR::RendererWorker:
    return "RendererWorker";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! AndroidThreadTypeKHR value as a std::string
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(AndroidThreadTypeKHR value) {
  return {to_string_literal(value)};
}

#endif // defined(XR_USE_PLATFORM_ANDROID)

//! @brief Enum class associated with XrVisibilityMaskTypeKHR
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrVisibilityMaskTypeKHR>
enum class VisibilityMaskTypeKHR : uint32_t {

  HiddenTriangleMesh = XR_VISIBILITY_MASK_TYPE_HIDDEN_TRIANGLE_MESH_KHR,

  VisibleTriangleMesh = XR_VISIBILITY_MASK_TYPE_VISIBLE_TRIANGLE_MESH_KHR,

  LineLoop = XR_VISIBILITY_MASK_TYPE_LINE_LOOP_KHR,

};

//! @brief Free function for retrieving the raw XrVisibilityMaskTypeKHR value
//! from a VisibilityMaskTypeKHR
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrVisibilityMaskTypeKHR
get(VisibilityMaskTypeKHR const &v) {
  return static_cast<XrVisibilityMaskTypeKHR>(v);
}

//! @brief Free function for retrieving the string name of a
//! VisibilityMaskTypeKHR value as a const char *
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(VisibilityMaskTypeKHR value) {
  switch (value) {

  case VisibilityMaskTypeKHR::HiddenTriangleMesh:
    return "HiddenTriangleMesh";

  case VisibilityMaskTypeKHR::VisibleTriangleMesh:
    return "VisibleTriangleMesh";

  case VisibilityMaskTypeKHR::LineLoop:
    return "LineLoop";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! VisibilityMaskTypeKHR value as a std::string
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(VisibilityMaskTypeKHR value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsDomainEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsDomainEXT>
enum class PerfSettingsDomainEXT : uint32_t {

  Cpu = XR_PERF_SETTINGS_DOMAIN_CPU_EXT,

  Gpu = XR_PERF_SETTINGS_DOMAIN_GPU_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsDomainEXT value
//! from a PerfSettingsDomainEXT
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsDomainEXT
get(PerfSettingsDomainEXT const &v) {
  return static_cast<XrPerfSettingsDomainEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsDomainEXT value as a const char *
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsDomainEXT value) {
  switch (value) {

  case PerfSettingsDomainEXT::Cpu:
    return "Cpu";

  case PerfSettingsDomainEXT::Gpu:
    return "Gpu";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsDomainEXT value as a std::string
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsDomainEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsSubDomainEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsSubDomainEXT>
enum class PerfSettingsSubDomainEXT : uint32_t {

  Compositing = XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT,

  Rendering = XR_PERF_SETTINGS_SUB_DOMAIN_RENDERING_EXT,

  Thermal = XR_PERF_SETTINGS_SUB_DOMAIN_THERMAL_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsSubDomainEXT value
//! from a PerfSettingsSubDomainEXT
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsSubDomainEXT
get(PerfSettingsSubDomainEXT const &v) {
  return static_cast<XrPerfSettingsSubDomainEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsSubDomainEXT value as a const char *
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsSubDomainEXT value) {
  switch (value) {

  case PerfSettingsSubDomainEXT::Compositing:
    return "Compositing";

  case PerfSettingsSubDomainEXT::Rendering:
    return "Rendering";

  case PerfSettingsSubDomainEXT::Thermal:
    return "Thermal";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsSubDomainEXT value as a std::string
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsSubDomainEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsLevelEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsLevelEXT>
enum class PerfSettingsLevelEXT : uint32_t {

  PowerSavings = XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT,

  SustainedLow = XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT,

  SustainedHigh = XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT,

  Boost = XR_PERF_SETTINGS_LEVEL_BOOST_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsLevelEXT value
//! from a PerfSettingsLevelEXT
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsLevelEXT
get(PerfSettingsLevelEXT const &v) {
  return static_cast<XrPerfSettingsLevelEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsLevelEXT value as a const char *
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsLevelEXT value) {
  switch (value) {

  case PerfSettingsLevelEXT::PowerSavings:
    return "PowerSavings";

  case PerfSettingsLevelEXT::SustainedLow:
    return "SustainedLow";

  case PerfSettingsLevelEXT::SustainedHigh:
    return "SustainedHigh";

  case PerfSettingsLevelEXT::Boost:
    return "Boost";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsLevelEXT value as a std::string
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsLevelEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsNotificationLevelEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsNotificationLevelEXT>
enum class PerfSettingsNotificationLevelEXT : uint32_t {

  XrPerfSettingsNotifLevelNormal = XR_PERF_SETTINGS_NOTIF_LEVEL_NORMAL_EXT,

  XrPerfSettingsNotifLevelWarning = XR_PERF_SETTINGS_NOTIF_LEVEL_WARNING_EXT,

  XrPerfSettingsNotifLevelImpaired = XR_PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED_EXT,

};

//! @brief Free function for retrieving the raw
//! XrPerfSettingsNotificationLevelEXT value from a
//! PerfSettingsNotificationLevelEXT
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsNotificationLevelEXT
get(PerfSettingsNotificationLevelEXT const &v) {
  return static_cast<XrPerfSettingsNotificationLevelEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsNotificationLevelEXT value as a const char *
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsNotificationLevelEXT value) {
  switch (value) {

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelNormal:
    return "XrPerfSettingsNotifLevelNormal";

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelWarning:
    return "XrPerfSettingsNotifLevelWarning";

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelImpaired:
    return "XrPerfSettingsNotifLevelImpaired";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsNotificationLevelEXT value as a std::string
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsNotificationLevelEXT value) {
  return {to_string_literal(value)};
}

//! @}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup enums Flags
 * @brief C++ flags classes corresponding to OpenXR C flags and flagbits, plus
 * associated utility functions.
 * @{
 */

//! @brief Flags class associated with XrInstanceCreateFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrInstanceCreateFlags>
enum class InstanceCreateFlagBits : XrFlags64 {};

using InstanceCreateFlags =
    Flags<InstanceCreateFlagBits, XrInstanceCreateFlags>;

//! @brief Flags class associated with XrSessionCreateFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSessionCreateFlags>
enum class SessionCreateFlagBits : XrFlags64 {};

using SessionCreateFlags = Flags<SessionCreateFlagBits, XrSessionCreateFlags>;

//! @brief Flags class associated with XrSpaceVelocityFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpaceVelocityFlags>
enum class SpaceVelocityFlagBits : XrFlags64 {
  LinearValidBit = XR_SPACE_VELOCITY_LINEAR_VALID_BIT,
  AngularValidBit = XR_SPACE_VELOCITY_ANGULAR_VALID_BIT
};

using SpaceVelocityFlags = Flags<SpaceVelocityFlagBits, XrSpaceVelocityFlags>;

//! @brief Flags class associated with XrSpaceLocationFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpaceLocationFlags>
enum class SpaceLocationFlagBits : XrFlags64 {
  OrientationValidBit = XR_SPACE_LOCATION_ORIENTATION_VALID_BIT,
  PositionValidBit = XR_SPACE_LOCATION_POSITION_VALID_BIT,
  OrientationTrackedBit = XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT,
  PositionTrackedBit = XR_SPACE_LOCATION_POSITION_TRACKED_BIT
};

using SpaceLocationFlags = Flags<SpaceLocationFlagBits, XrSpaceLocationFlags>;

//! @brief Flags class associated with XrSwapchainCreateFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSwapchainCreateFlags>
enum class SwapchainCreateFlagBits : XrFlags64 {
  ProtectedContentBit = XR_SWAPCHAIN_CREATE_PROTECTED_CONTENT_BIT,
  StaticImageBit = XR_SWAPCHAIN_CREATE_STATIC_IMAGE_BIT
};

using SwapchainCreateFlags =
    Flags<SwapchainCreateFlagBits, XrSwapchainCreateFlags>;

//! @brief Flags class associated with XrSwapchainUsageFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSwapchainUsageFlags>
enum class SwapchainUsageFlagBits : XrFlags64 {
  ColorAttachmentBit = XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT,
  DepthStencilAttachmentBit = XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
  UnorderedAccessBit = XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT,
  TransferSrcBit = XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT,
  TransferDstBit = XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT,
  SampledBit = XR_SWAPCHAIN_USAGE_SAMPLED_BIT,
  MutableFormatBit = XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT
};

using SwapchainUsageFlags =
    Flags<SwapchainUsageFlagBits, XrSwapchainUsageFlags>;

//! @brief Flags class associated with XrCompositionLayerFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrCompositionLayerFlags>
enum class CompositionLayerFlagBits : XrFlags64 {
  CorrectChromaticAberrationBit =
      XR_COMPOSITION_LAYER_CORRECT_CHROMATIC_ABERRATION_BIT,
  BlendTextureSourceAlphaBit =
      XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT,
  UnpremultipliedAlphaBit = XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT
};

using CompositionLayerFlags =
    Flags<CompositionLayerFlagBits, XrCompositionLayerFlags>;

//! @brief Flags class associated with XrViewStateFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrViewStateFlags>
enum class ViewStateFlagBits : XrFlags64 {
  OrientationValidBit = XR_VIEW_STATE_ORIENTATION_VALID_BIT,
  PositionValidBit = XR_VIEW_STATE_POSITION_VALID_BIT,
  OrientationTrackedBit = XR_VIEW_STATE_ORIENTATION_TRACKED_BIT,
  PositionTrackedBit = XR_VIEW_STATE_POSITION_TRACKED_BIT
};

using ViewStateFlags = Flags<ViewStateFlagBits, XrViewStateFlags>;

//! @brief Flags class associated with XrInputSourceLocalizedNameFlags
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrInputSourceLocalizedNameFlags>
enum class InputSourceLocalizedNameFlagBits : XrFlags64 {
  UserPathBit = XR_INPUT_SOURCE_LOCALIZED_NAME_USER_PATH_BIT,
  InteractionProfileBit =
      XR_INPUT_SOURCE_LOCALIZED_NAME_INTERACTION_PROFILE_BIT,
  ComponentBit = XR_INPUT_SOURCE_LOCALIZED_NAME_COMPONENT_BIT
};

using InputSourceLocalizedNameFlags =
    Flags<InputSourceLocalizedNameFlagBits, XrInputSourceLocalizedNameFlags>;

//! @brief Flags class associated with XrDebugUtilsMessageSeverityFlagsEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrDebugUtilsMessageSeverityFlagsEXT>
enum class DebugUtilsMessageSeverityFlagBitsEXT : XrFlags64 {
  XrDebugUtilsMessageSeverityVerboseBit =
      XR_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
  XrDebugUtilsMessageSeverityInfoBit =
      XR_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT,
  XrDebugUtilsMessageSeverityWarningBit =
      XR_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT,
  XrDebugUtilsMessageSeverityErrorBit =
      XR_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT
};

using DebugUtilsMessageSeverityFlagsEXT =
    Flags<DebugUtilsMessageSeverityFlagBitsEXT,
          XrDebugUtilsMessageSeverityFlagsEXT>;

//! @brief Flags class associated with XrDebugUtilsMessageTypeFlagsEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrDebugUtilsMessageTypeFlagsEXT>
enum class DebugUtilsMessageTypeFlagBitsEXT : XrFlags64 {
  XrDebugUtilsMessageTypeGeneralBit =
      XR_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT,
  XrDebugUtilsMessageTypeValidationBit =
      XR_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT,
  XrDebugUtilsMessageTypePerformanceBit =
      XR_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
  XrDebugUtilsMessageTypeConformanceBit =
      XR_DEBUG_UTILS_MESSAGE_TYPE_CONFORMANCE_BIT_EXT
};

using DebugUtilsMessageTypeFlagsEXT =
    Flags<DebugUtilsMessageTypeFlagBitsEXT, XrDebugUtilsMessageTypeFlagsEXT>;

//! @}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup result_helpers Result helper free functions
 * @{
 */
//! @brief Return true if the Result is negative, indicating a failure.
//! Equivalent of XR_FAILED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool failed(Result v) {
  return static_cast<int>(v) < 0;
}

//! @brief Return true if the result is non-negative, indicating a success or
//! non-error result. Equivalent of XR_SUCCEEDED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool succeeded(Result v) {
  return static_cast<int>(v) >= 0;
}

//! @brief Return true if the result is exactly equal to Result::Success.
//! Equivalent of XR_UNQUALIFIED_SUCCESS()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool unqualifiedSuccess(Result v) {
  return v == Result::Success;
}
//! @}

//! @brief `<` comparison between Result and integer, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Result lhs, int rhs) {
  return get(lhs) < rhs;
}

//! @brief `<` comparison between integer and Result, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(int lhs, Result rhs) {
  return lhs < get(rhs);
}

//! @brief `>` comparison between Result and integer, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Result lhs, int rhs) {
  return get(lhs) > rhs;
}

//! @brief `>` comparison between integer and Result, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(int lhs, Result rhs) {
  return lhs > get(rhs);
}

//! @brief `<=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Result lhs, int rhs) {
  return get(lhs) <= rhs;
}

//! @brief `<=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(int lhs, Result rhs) {
  return lhs <= get(rhs);
}

//! @brief `>=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Result lhs, int rhs) {
  return get(lhs) >= rhs;
}

//! @brief `>=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(int lhs, Result rhs) {
  return lhs >= get(rhs);
}

//! @brief `==` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Result lhs, int rhs) {
  return get(lhs) == rhs;
}

//! @brief `==` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(int lhs, Result rhs) {
  return lhs == get(rhs);
}

//! @brief `!=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Result lhs, int rhs) {
  return get(lhs) != rhs;
}

//! @brief `!=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(int lhs, Result rhs) {
  return lhs != get(rhs);
}

} // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

//! Implementation details
namespace impl {
#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif

class ErrorCategoryImpl : public std::error_category {
public:
  virtual const char *name() const noexcept override {
    return OPENXR_HPP_NAMESPACE_STRING "::Result";
  }
  virtual std::string message(int ev) const override {
    return to_string(static_cast<Result>(ev));
  }
};

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#undef noexcept
#endif

OPENXR_HPP_INLINE const std::error_category &errorCategory() {
  static impl::ErrorCategoryImpl instance;
  return instance;
}

OPENXR_HPP_INLINE std::error_code make_error_code(Result e) {
  return std::error_code(static_cast<int>(e), errorCategory());
}

OPENXR_HPP_INLINE std::error_condition make_error_condition(Result e) {
  return std::error_condition(static_cast<int>(e), errorCategory());
}

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif
} // namespace impl

//! OpenXR exceptions
namespace exceptions {
/*!
 * @defgroup exceptions Exceptions
 *
 * @{
 */
/*!
 * @defgroup base_exceptions Exception base classes
 * @{
 */
//! @brief Base class for all OpenXR exceptions.
//!
//! Only used for catching all OpenXR exceptions.
class Error {
public:
  virtual ~Error() = default;

  virtual const char *what() const noexcept = 0;
};

//! @brief OpenXR logic error base exception class.
//!
//! Derives from both Error and std::logic_error for flexibility in catching.
class LogicError : public Error, public std::logic_error {
public:
  explicit LogicError(const std::string &what)
      : Error(), std::logic_error(what) {}
  explicit LogicError(char const *what) : Error(), std::logic_error(what) {}
  virtual ~LogicError() = default;

  virtual const char *what() const noexcept { return std::logic_error::what(); }
};

//! @brief OpenXR system error exception class - may be derived from or thrown
//! directly.
//!
//! Derives from both Error and std::system_error for flexibility in catching.
class SystemError : public Error, public std::system_error {
public:
  SystemError(std::error_code ec) : Error(), std::system_error(ec) {}
  SystemError(std::error_code ec, std::string const &what)
      : Error(), std::system_error(ec, what) {}
  SystemError(std::error_code ec, char const *what)
      : Error(), std::system_error(ec, what) {}
  SystemError(int ev, std::error_category const &ecat)
      : Error(), std::system_error(ev, ecat) {}
  SystemError(int ev, std::error_category const &ecat, std::string const &what)
      : Error(), std::system_error(ev, ecat, what) {}
  SystemError(int ev, std::error_category const &ecat, char const *what)
      : Error(), std::system_error(ev, ecat, what) {}
  virtual ~SystemError() = default;

  virtual const char *what() const noexcept {
    return std::system_error::what();
  }
};

// end of base_exceptions
//! @}
#if defined(_MSC_VER) && (_MSC_VER == 1800)
#undef noexcept
#endif

/*!
 * @defgroup result_exceptions Result-specific exceptions
 * @{
 */
//! @todo identify which errors would be considered LogicError and subclass that
//! instead. Add to XML?

//! @brief Exception class associated with the Result::ErrorValidationFailure
//! aka XR_ERROR_VALIDATION_FAILURE result code.
class ValidationFailureError : public SystemError {
public:
  ValidationFailureError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorValidationFailure),
                    message) {}

  ValidationFailureError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorValidationFailure),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorRuntimeFailure aka
//! XR_ERROR_RUNTIME_FAILURE result code.
class RuntimeFailureError : public SystemError {
public:
  RuntimeFailureError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorRuntimeFailure),
                    message) {}

  RuntimeFailureError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorRuntimeFailure),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorOutOfMemory aka
//! XR_ERROR_OUT_OF_MEMORY result code.
class OutOfMemoryError : public SystemError {
public:
  OutOfMemoryError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorOutOfMemory), message) {}

  OutOfMemoryError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorOutOfMemory), message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorApiVersionUnsupported aka XR_ERROR_API_VERSION_UNSUPPORTED
//! result code.
class ApiVersionUnsupportedError : public SystemError {
public:
  ApiVersionUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorApiVersionUnsupported),
                    message) {}

  ApiVersionUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorApiVersionUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorInitializationFailed
//! aka XR_ERROR_INITIALIZATION_FAILED result code.
class InitializationFailedError : public SystemError {
public:
  InitializationFailedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorInitializationFailed),
                    message) {}

  InitializationFailedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorInitializationFailed),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFunctionUnsupported
//! aka XR_ERROR_FUNCTION_UNSUPPORTED result code.
class FunctionUnsupportedError : public SystemError {
public:
  FunctionUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFunctionUnsupported),
                    message) {}

  FunctionUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFunctionUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFeatureUnsupported
//! aka XR_ERROR_FEATURE_UNSUPPORTED result code.
class FeatureUnsupportedError : public SystemError {
public:
  FeatureUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFeatureUnsupported),
                    message) {}

  FeatureUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFeatureUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorExtensionNotPresent
//! aka XR_ERROR_EXTENSION_NOT_PRESENT result code.
class ExtensionNotPresentError : public SystemError {
public:
  ExtensionNotPresentError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorExtensionNotPresent),
                    message) {}

  ExtensionNotPresentError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorExtensionNotPresent),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLimitReached aka
//! XR_ERROR_LIMIT_REACHED result code.
class LimitReachedError : public SystemError {
public:
  LimitReachedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLimitReached), message) {
  }

  LimitReachedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLimitReached), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorSizeInsufficient aka
//! XR_ERROR_SIZE_INSUFFICIENT result code.
class SizeInsufficientError : public SystemError {
public:
  SizeInsufficientError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSizeInsufficient),
                    message) {}

  SizeInsufficientError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSizeInsufficient),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorHandleInvalid aka
//! XR_ERROR_HANDLE_INVALID result code.
class HandleInvalidError : public SystemError {
public:
  HandleInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorHandleInvalid),
                    message) {}

  HandleInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorHandleInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorInstanceLost aka
//! XR_ERROR_INSTANCE_LOST result code.
class InstanceLostError : public SystemError {
public:
  InstanceLostError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorInstanceLost), message) {
  }

  InstanceLostError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorInstanceLost), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorSessionRunning aka
//! XR_ERROR_SESSION_RUNNING result code.
class SessionRunningError : public SystemError {
public:
  SessionRunningError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionRunning),
                    message) {}

  SessionRunningError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionRunning),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotRunning
//! aka XR_ERROR_SESSION_NOT_RUNNING result code.
class SessionNotRunningError : public SystemError {
public:
  SessionNotRunningError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotRunning),
                    message) {}

  SessionNotRunningError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotRunning),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionLost aka
//! XR_ERROR_SESSION_LOST result code.
class SessionLostError : public SystemError {
public:
  SessionLostError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionLost), message) {}

  SessionLostError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionLost), message) {}
};

//! @brief Exception class associated with the Result::ErrorSystemInvalid aka
//! XR_ERROR_SYSTEM_INVALID result code.
class SystemInvalidError : public SystemError {
public:
  SystemInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSystemInvalid),
                    message) {}

  SystemInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSystemInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathInvalid aka
//! XR_ERROR_PATH_INVALID result code.
class PathInvalidError : public SystemError {
public:
  PathInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathInvalid), message) {}

  PathInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorPathCountExceeded
//! aka XR_ERROR_PATH_COUNT_EXCEEDED result code.
class PathCountExceededError : public SystemError {
public:
  PathCountExceededError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathCountExceeded),
                    message) {}

  PathCountExceededError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathCountExceeded),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathFormatInvalid
//! aka XR_ERROR_PATH_FORMAT_INVALID result code.
class PathFormatInvalidError : public SystemError {
public:
  PathFormatInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathFormatInvalid),
                    message) {}

  PathFormatInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathFormatInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathUnsupported aka
//! XR_ERROR_PATH_UNSUPPORTED result code.
class PathUnsupportedError : public SystemError {
public:
  PathUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathUnsupported),
                    message) {}

  PathUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLayerInvalid aka
//! XR_ERROR_LAYER_INVALID result code.
class LayerInvalidError : public SystemError {
public:
  LayerInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLayerInvalid), message) {
  }

  LayerInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLayerInvalid), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorLayerLimitExceeded
//! aka XR_ERROR_LAYER_LIMIT_EXCEEDED result code.
class LayerLimitExceededError : public SystemError {
public:
  LayerLimitExceededError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLayerLimitExceeded),
                    message) {}

  LayerLimitExceededError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLayerLimitExceeded),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSwapchainRectInvalid
//! aka XR_ERROR_SWAPCHAIN_RECT_INVALID result code.
class SwapchainRectInvalidError : public SystemError {
public:
  SwapchainRectInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSwapchainRectInvalid),
                    message) {}

  SwapchainRectInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSwapchainRectInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorSwapchainFormatUnsupported aka
//! XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED result code.
class SwapchainFormatUnsupportedError : public SystemError {
public:
  SwapchainFormatUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorSwapchainFormatUnsupported),
            message) {}

  SwapchainFormatUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorSwapchainFormatUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorActionTypeMismatch
//! aka XR_ERROR_ACTION_TYPE_MISMATCH result code.
class ActionTypeMismatchError : public SystemError {
public:
  ActionTypeMismatchError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorActionTypeMismatch),
                    message) {}

  ActionTypeMismatchError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorActionTypeMismatch),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotReady aka
//! XR_ERROR_SESSION_NOT_READY result code.
class SessionNotReadyError : public SystemError {
public:
  SessionNotReadyError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotReady),
                    message) {}

  SessionNotReadyError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotReady),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotStopping
//! aka XR_ERROR_SESSION_NOT_STOPPING result code.
class SessionNotStoppingError : public SystemError {
public:
  SessionNotStoppingError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotStopping),
                    message) {}

  SessionNotStoppingError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotStopping),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorTimeInvalid aka
//! XR_ERROR_TIME_INVALID result code.
class TimeInvalidError : public SystemError {
public:
  TimeInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorTimeInvalid), message) {}

  TimeInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorTimeInvalid), message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorReferenceSpaceUnsupported aka
//! XR_ERROR_REFERENCE_SPACE_UNSUPPORTED result code.
class ReferenceSpaceUnsupportedError : public SystemError {
public:
  ReferenceSpaceUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorReferenceSpaceUnsupported),
            message) {}

  ReferenceSpaceUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorReferenceSpaceUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorFileAccessError aka
//! XR_ERROR_FILE_ACCESS_ERROR result code.
class FileAccessError : public SystemError {
public:
  FileAccessError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFileAccessError),
                    message) {}

  FileAccessError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFileAccessError),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFileContentsInvalid
//! aka XR_ERROR_FILE_CONTENTS_INVALID result code.
class FileContentsInvalidError : public SystemError {
public:
  FileContentsInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFileContentsInvalid),
                    message) {}

  FileContentsInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFileContentsInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorFormFactorUnsupported aka XR_ERROR_FORM_FACTOR_UNSUPPORTED
//! result code.
class FormFactorUnsupportedError : public SystemError {
public:
  FormFactorUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnsupported),
                    message) {}

  FormFactorUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnsupported),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorFormFactorUnavailable aka XR_ERROR_FORM_FACTOR_UNAVAILABLE
//! result code.
class FormFactorUnavailableError : public SystemError {
public:
  FormFactorUnavailableError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnavailable),
                    message) {}

  FormFactorUnavailableError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnavailable),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorApiLayerNotPresent
//! aka XR_ERROR_API_LAYER_NOT_PRESENT result code.
class ApiLayerNotPresentError : public SystemError {
public:
  ApiLayerNotPresentError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorApiLayerNotPresent),
                    message) {}

  ApiLayerNotPresentError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorApiLayerNotPresent),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorCallOrderInvalid aka
//! XR_ERROR_CALL_ORDER_INVALID result code.
class CallOrderInvalidError : public SystemError {
public:
  CallOrderInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorCallOrderInvalid),
                    message) {}

  CallOrderInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorCallOrderInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorGraphicsDeviceInvalid aka XR_ERROR_GRAPHICS_DEVICE_INVALID
//! result code.
class GraphicsDeviceInvalidError : public SystemError {
public:
  GraphicsDeviceInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorGraphicsDeviceInvalid),
                    message) {}

  GraphicsDeviceInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorGraphicsDeviceInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPoseInvalid aka
//! XR_ERROR_POSE_INVALID result code.
class PoseInvalidError : public SystemError {
public:
  PoseInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPoseInvalid), message) {}

  PoseInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPoseInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorIndexOutOfRange aka
//! XR_ERROR_INDEX_OUT_OF_RANGE result code.
class IndexOutOfRangeError : public SystemError {
public:
  IndexOutOfRangeError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorIndexOutOfRange),
                    message) {}

  IndexOutOfRangeError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorIndexOutOfRange),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorViewConfigurationTypeUnsupported aka
//! XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED result code.
class ViewConfigurationTypeUnsupportedError : public SystemError {
public:
  ViewConfigurationTypeUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(
                        Result::ErrorViewConfigurationTypeUnsupported),
                    message) {}

  ViewConfigurationTypeUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(
                        Result::ErrorViewConfigurationTypeUnsupported),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorEnvironmentBlendModeUnsupported aka
//! XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED result code.
class EnvironmentBlendModeUnsupportedError : public SystemError {
public:
  EnvironmentBlendModeUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorEnvironmentBlendModeUnsupported),
            message) {}

  EnvironmentBlendModeUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorEnvironmentBlendModeUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorNameDuplicated aka
//! XR_ERROR_NAME_DUPLICATED result code.
class NameDuplicatedError : public SystemError {
public:
  NameDuplicatedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorNameDuplicated),
                    message) {}

  NameDuplicatedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorNameDuplicated),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorNameInvalid aka
//! XR_ERROR_NAME_INVALID result code.
class NameInvalidError : public SystemError {
public:
  NameInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorNameInvalid), message) {}

  NameInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorNameInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorActionsetNotAttached
//! aka XR_ERROR_ACTIONSET_NOT_ATTACHED result code.
class ActionsetNotAttachedError : public SystemError {
public:
  ActionsetNotAttachedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorActionsetNotAttached),
                    message) {}

  ActionsetNotAttachedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorActionsetNotAttached),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorActionsetsAlreadyAttached aka
//! XR_ERROR_ACTIONSETS_ALREADY_ATTACHED result code.
class ActionsetsAlreadyAttachedError : public SystemError {
public:
  ActionsetsAlreadyAttachedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorActionsetsAlreadyAttached),
            message) {}

  ActionsetsAlreadyAttachedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorActionsetsAlreadyAttached),
            message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorLocalizedNameDuplicated aka XR_ERROR_LOCALIZED_NAME_DUPLICATED
//! result code.
class LocalizedNameDuplicatedError : public SystemError {
public:
  LocalizedNameDuplicatedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameDuplicated),
                    message) {}

  LocalizedNameDuplicatedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameDuplicated),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLocalizedNameInvalid
//! aka XR_ERROR_LOCALIZED_NAME_INVALID result code.
class LocalizedNameInvalidError : public SystemError {
public:
  LocalizedNameInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameInvalid),
                    message) {}

  LocalizedNameInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorAndroidThreadSettingsIdInvalidKHR aka
//! XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR result code.
class AndroidThreadSettingsIdInvalidKHRError : public SystemError {
public:
  AndroidThreadSettingsIdInvalidKHRError(std::string const &message)
      : SystemError(impl::make_error_code(
                        Result::ErrorAndroidThreadSettingsIdInvalidKHR),
                    message) {}

  AndroidThreadSettingsIdInvalidKHRError(char const *message)
      : SystemError(impl::make_error_code(
                        Result::ErrorAndroidThreadSettingsIdInvalidKHR),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorAndroidThreadSettingsFailureKHR aka
//! XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR result code.
class AndroidThreadSettingsFailureKHRError : public SystemError {
public:
  AndroidThreadSettingsFailureKHRError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorAndroidThreadSettingsFailureKHR),
            message) {}

  AndroidThreadSettingsFailureKHRError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorAndroidThreadSettingsFailureKHR),
            message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorCreateSpatialAnchorFailedMSFT aka
//! XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT result code.
class CreateSpatialAnchorFailedMSFTError : public SystemError {
public:
  CreateSpatialAnchorFailedMSFTError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorCreateSpatialAnchorFailedMSFT),
            message) {}

  CreateSpatialAnchorFailedMSFTError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorCreateSpatialAnchorFailedMSFT),
            message) {}
};

// end of result_exceptions
//! @}

/*!
 * @brief Throws the best exception for a result code.
 *
 * Takes a result code and a message (usually the method triggering the
 * exception) and throws the most-specific exception available for that result
 * code. As a fallback, it will throw a SystemError directly.
 */
OPENXR_HPP_INLINE void throwResultException(Result result,
                                            char const *message) {
  switch (result) {

  case Result::Success:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::TimeoutExpired:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SessionLossPending:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::EventUnavailable:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SpaceBoundsUnavailable:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SessionNotFocused:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::FrameDiscarded:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::ErrorValidationFailure:
    throw ValidationFailureError(message);

  case Result::ErrorRuntimeFailure:
    throw RuntimeFailureError(message);

  case Result::ErrorOutOfMemory:
    throw OutOfMemoryError(message);

  case Result::ErrorApiVersionUnsupported:
    throw ApiVersionUnsupportedError(message);

  case Result::ErrorInitializationFailed:
    throw InitializationFailedError(message);

  case Result::ErrorFunctionUnsupported:
    throw FunctionUnsupportedError(message);

  case Result::ErrorFeatureUnsupported:
    throw FeatureUnsupportedError(message);

  case Result::ErrorExtensionNotPresent:
    throw ExtensionNotPresentError(message);

  case Result::ErrorLimitReached:
    throw LimitReachedError(message);

  case Result::ErrorSizeInsufficient:
    throw SizeInsufficientError(message);

  case Result::ErrorHandleInvalid:
    throw HandleInvalidError(message);

  case Result::ErrorInstanceLost:
    throw InstanceLostError(message);

  case Result::ErrorSessionRunning:
    throw SessionRunningError(message);

  case Result::ErrorSessionNotRunning:
    throw SessionNotRunningError(message);

  case Result::ErrorSessionLost:
    throw SessionLostError(message);

  case Result::ErrorSystemInvalid:
    throw SystemInvalidError(message);

  case Result::ErrorPathInvalid:
    throw PathInvalidError(message);

  case Result::ErrorPathCountExceeded:
    throw PathCountExceededError(message);

  case Result::ErrorPathFormatInvalid:
    throw PathFormatInvalidError(message);

  case Result::ErrorPathUnsupported:
    throw PathUnsupportedError(message);

  case Result::ErrorLayerInvalid:
    throw LayerInvalidError(message);

  case Result::ErrorLayerLimitExceeded:
    throw LayerLimitExceededError(message);

  case Result::ErrorSwapchainRectInvalid:
    throw SwapchainRectInvalidError(message);

  case Result::ErrorSwapchainFormatUnsupported:
    throw SwapchainFormatUnsupportedError(message);

  case Result::ErrorActionTypeMismatch:
    throw ActionTypeMismatchError(message);

  case Result::ErrorSessionNotReady:
    throw SessionNotReadyError(message);

  case Result::ErrorSessionNotStopping:
    throw SessionNotStoppingError(message);

  case Result::ErrorTimeInvalid:
    throw TimeInvalidError(message);

  case Result::ErrorReferenceSpaceUnsupported:
    throw ReferenceSpaceUnsupportedError(message);

  case Result::ErrorFileAccessError:
    throw FileAccessError(message);

  case Result::ErrorFileContentsInvalid:
    throw FileContentsInvalidError(message);

  case Result::ErrorFormFactorUnsupported:
    throw FormFactorUnsupportedError(message);

  case Result::ErrorFormFactorUnavailable:
    throw FormFactorUnavailableError(message);

  case Result::ErrorApiLayerNotPresent:
    throw ApiLayerNotPresentError(message);

  case Result::ErrorCallOrderInvalid:
    throw CallOrderInvalidError(message);

  case Result::ErrorGraphicsDeviceInvalid:
    throw GraphicsDeviceInvalidError(message);

  case Result::ErrorPoseInvalid:
    throw PoseInvalidError(message);

  case Result::ErrorIndexOutOfRange:
    throw IndexOutOfRangeError(message);

  case Result::ErrorViewConfigurationTypeUnsupported:
    throw ViewConfigurationTypeUnsupportedError(message);

  case Result::ErrorEnvironmentBlendModeUnsupported:
    throw EnvironmentBlendModeUnsupportedError(message);

  case Result::ErrorNameDuplicated:
    throw NameDuplicatedError(message);

  case Result::ErrorNameInvalid:
    throw NameInvalidError(message);

  case Result::ErrorActionsetNotAttached:
    throw ActionsetNotAttachedError(message);

  case Result::ErrorActionsetsAlreadyAttached:
    throw ActionsetsAlreadyAttachedError(message);

  case Result::ErrorLocalizedNameDuplicated:
    throw LocalizedNameDuplicatedError(message);

  case Result::ErrorLocalizedNameInvalid:
    throw LocalizedNameInvalidError(message);

  case Result::ErrorAndroidThreadSettingsIdInvalidKHR:
    throw AndroidThreadSettingsIdInvalidKHRError(message);

  case Result::ErrorAndroidThreadSettingsFailureKHR:
    throw AndroidThreadSettingsFailureKHRError(message);

  case Result::ErrorCreateSpatialAnchorFailedMSFT:
    throw CreateSpatialAnchorFailedMSFTError(message);

  default:
    throw SystemError(impl::make_error_code(result));
  }
}
//! @}
} // namespace exceptions
} // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_DOXYGEN)
namespace std {
template <>
struct is_error_code_enum<OPENXR_HPP_NAMESPACE::Result> : public true_type {};
} // namespace std
#endif // !defined(OPENXR_HPP_DOXYGEN)
#endif // !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup return_results Returning results
 * @brief Types and functions used by API call wrappers to return output in a
 * friendly, C++ manner.
 *
 * A user of openxr.hpp will not typically call the functions here directly,
 * but knowing how they work could be useful.
 * @{
 */

/*!
 * @brief Contains a Result enumerant and a returned value.
 *
 * Implicitly convertible to std::tuple<> so you can do `std::tie(result, value)
 * = callThatReturnsResultValue()`
 *
 * @ingroup utilities
 */
template <typename T> struct ResultValue {
  ResultValue(Result r, T const &v) : result(r), value(v) {}

  ResultValue(Result r, T &&v) : result(r), value(std::move(v)) {}

  Result result;
  T value;

  operator std::tuple<Result &, T &>() {
    return std::tuple<Result &, T &>(result, value);
  }
};

/*!
 * @brief Computes the return type of a function (in enhanced mode) with no
 * non-Result::Success success codes and potentially an output value of type T.
 *
 * The behavior differs based on whether or not you have
 * OPENXR_HPP_NO_EXCEPTIONS defined. If it is defined, then all functions return
 * either a Result (for T=void) or a ResultValue<T>. Otherwise, with exceptions
 * enabled, the Result does not need to be returned in these cases, so the
 * return type is T (which may be void).
 */
template <typename T> struct ResultValueType;

#ifdef OPENXR_HPP_NO_EXCEPTIONS
template <typename T> struct ResultValueType { typedef ResultValue<T> type; };
template <> struct ResultValueType<void> { typedef Result type; };
#else
template <typename T> struct ResultValueType { typedef T type; };
template <> struct ResultValueType<void> { typedef void type; };
#endif

namespace impl {
/*!
 * @brief Returned by enhanced-mode functions with no output value and no
 * non-Result::Success success codes.
 *
 * On failure:
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns nothing (void)
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns Result.
 */
OPENXR_HPP_INLINE ResultValueType<void>::type
createResultValue(Result result, char const *message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(result == Result::Success);
  return result;
#else
  if (failed(result)) {
    exceptions::throwResultException(result, message);
  }
#endif
}

/*!
 * @brief Returned by enhanced-mode functions with output value of type T and no
 * non-Result::Success success codes.
 *
 * On failure:
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type T
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T> containing both the result (which may be an error or
 * Result::Success) and the value.
 */
template <typename T>
OPENXR_HPP_INLINE typename ResultValueType<T>::type
createResultValue(Result result, T &data, char const *message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(result == Result::Success);
  return ResultValue<T>(result, std::move(data));
#else
  if (failed(result)) {
    exceptions::throwResultException(result, message);
  }
  return std::move(data);
#endif
}

/*!
 * @brief Returned by enhanced-mode functions with no output value and at least
 * one success code specified that is not Result::Success.
 *
 * Return type is always Result.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns Result (which may be Result::Success, or a non-Result::Success
 * success code)
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns Result (which may be an error, Result::Success, or a
 * non-Result::Success success code).
 */
OPENXR_HPP_INLINE Result
createResultValue(Result result, char const *message,
                  std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
#endif
  return result;
}

/*!
 * @brief Returned by enhanced-mode functions with an output value of type T and
 * at least one success code specified that is not Result::Success.
 *
 * Return type is always ResultValue<T>, containing both a Result and the output
 * of type T.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns ResultValue<T>, containing both a Result (which may be
 * Result::Success, or a non-Result::Success success code) and the output of
 * type T.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the output of
 * type T.
 */
template <typename T>
OPENXR_HPP_INLINE ResultValue<T>
createResultValue(Result result, T &data, char const *message,
                  std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
#endif
  return ResultValue<T>(result, data);
}

#ifndef OPENXR_HPP_NO_SMART_HANDLE
/*!
 * @brief Returned by enhanced-mode functions that create a UniqueHandle<T, D>
 * (a handle of type T, with deleter using dispatch type D) and
 * no non-Result::Success success codes.
 *
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns UniqueHandle<T, D>.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which
 * may be an error, Result::Success, or a non-Result::Success success code) and
 * the UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle<T, D>>::type
createResultValue(
    Result result, T &data,
    typename traits::UniqueHandleTraits<T, D>::deleter const &deleter,
    char const *message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(result == Result::Success);
  return ResultValue<UniqueHandle<T, D>>(
      result, UniqueHandle<T, D>(std::move(data), deleter));
#else
  if (failed(result)) {
    exceptions::throwResultException(result, message);
  }
  return UniqueHandle<T, D>(data, deleter);
#endif
}

/*!
 * @brief Returned by enhanced-mode functions that create a UniqueHandle<T, D>
 * (a handle of type T, with deleter using dispatch type D) and
 * at least one success code specified that is not Result::Success.
 *
 * Return type is always ResultValue<UniqueHandle<T, D>>, containing both a
 * Result and the UniqueHandle<T, D> (which may be null).
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which
 * may be Result::Success, or a non-Result::Success success code) and the
 * UniqueHandle<T, D>.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the
 * UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE ResultValue<UniqueHandle<T, D>> createResultValue(
    Result result, T &data,
    typename traits::UniqueHandleTraits<T, D>::deleter const &deleter,
    char const *message, std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
  return ResultValue<UniqueHandle<T, D>>(
      result, UniqueHandle<T, D>(std::move(data), deleter));
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
  return ResultValue<UniqueHandle<T, D>>(result,
                                         UniqueHandle<T, D>{data, deleter});
#endif
}
#endif

} // namespace impl

//! @}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

struct ApiLayerProperties;
struct ExtensionProperties;
struct ApplicationInfo;
struct InstanceCreateInfo;
struct InstanceProperties;
struct EventDataBuffer;
struct SystemGetInfo;
struct SystemGraphicsProperties;
struct SystemTrackingProperties;
struct SystemProperties;
struct SessionCreateInfo;
struct Vector3f;
struct SpaceVelocity;
struct Quaternionf;
struct Posef;
struct ReferenceSpaceCreateInfo;
struct Extent2Df;
struct ActionSpaceCreateInfo;
struct SpaceLocation;
struct ViewConfigurationProperties;
struct ViewConfigurationView;
struct SwapchainCreateInfo;
struct SwapchainImageBaseHeader;
struct SwapchainImageAcquireInfo;
struct SwapchainImageWaitInfo;
struct SwapchainImageReleaseInfo;
struct SessionBeginInfo;
struct FrameWaitInfo;
struct FrameState;
struct FrameBeginInfo;
struct CompositionLayerBaseHeader;
struct FrameEndInfo;
struct ViewLocateInfo;
struct ViewState;
struct Fovf;
struct View;
struct ActionSetCreateInfo;
struct ActionCreateInfo;
struct ActionSuggestedBinding;
struct InteractionProfileSuggestedBinding;
struct SessionActionSetsAttachInfo;
struct InteractionProfileState;
struct ActionStateGetInfo;
struct ActionStateBoolean;
struct ActionStateFloat;
struct Vector2f;
struct ActionStateVector2f;
struct ActionStatePose;
struct ActiveActionSet;
struct ActionsSyncInfo;
struct BoundSourcesForActionEnumerateInfo;
struct InputSourceLocalizedNameGetInfo;
struct HapticActionInfo;
struct HapticBaseHeader;
struct BaseInStructure;
struct BaseOutStructure;
struct Offset2Di;
struct Extent2Di;
struct Rect2Di;
struct SwapchainSubImage;
struct CompositionLayerProjectionView;
struct CompositionLayerProjection;
struct CompositionLayerQuad;
struct EventDataBaseHeader;
struct EventDataEventsLost;
struct EventDataInstanceLossPending;
struct EventDataSessionStateChanged;
struct EventDataReferenceSpaceChangePending;
struct EventDataInteractionProfileChanged;
struct HapticVibration;
struct Offset2Df;
struct Rect2Df;
struct Vector4f;
struct Color4f;
struct CompositionLayerCubeKHR;
struct InstanceCreateInfoAndroidKHR;
struct CompositionLayerDepthInfoKHR;
struct VulkanSwapchainFormatListCreateInfoKHR;
struct CompositionLayerCylinderKHR;
struct CompositionLayerEquirectKHR;
struct GraphicsBindingOpenGLWin32KHR;
struct GraphicsBindingOpenGLXlibKHR;
struct GraphicsBindingOpenGLXcbKHR;
struct GraphicsBindingOpenGLWaylandKHR;
struct SwapchainImageOpenGLKHR;
struct GraphicsRequirementsOpenGLKHR;
struct GraphicsBindingOpenGLESAndroidKHR;
struct SwapchainImageOpenGLESKHR;
struct GraphicsRequirementsOpenGLESKHR;
struct GraphicsBindingVulkanKHR;
struct SwapchainImageVulkanKHR;
struct GraphicsRequirementsVulkanKHR;
struct GraphicsBindingD3D11KHR;
struct SwapchainImageD3D11KHR;
struct GraphicsRequirementsD3D11KHR;
struct GraphicsBindingD3D12KHR;
struct SwapchainImageD3D12KHR;
struct GraphicsRequirementsD3D12KHR;
struct VisibilityMaskKHR;
struct EventDataVisibilityMaskChangedKHR;
struct EventDataPerfSettingsEXT;
struct DebugUtilsObjectNameInfoEXT;
struct DebugUtilsLabelEXT;
struct DebugUtilsMessengerCallbackDataEXT;
struct DebugUtilsMessengerCreateInfoEXT;
struct SpatialAnchorCreateInfoMSFT;
struct SpatialAnchorSpaceCreateInfoMSFT;
} // namespace OPENXR_HPP_NAMESPACE
namespace OPENXR_HPP_NAMESPACE {

//! Type traits
namespace traits {
//! Type trait associating an ObjectType enum value with its C++ type.
template <ObjectType o> struct cpp_type;
} // namespace traits

// forward declarations

class Instance;
class Session;
class Space;
class Action;
class Swapchain;
class ActionSet;
class DebugUtilsMessengerEXT;
class SpatialAnchorMSFT;
/*!
 * @defgroup handles Handle types
 * @brief Wrappers for OpenXR handle types, with associated functions mapped as
 * methods.
 * @{
 */
/*!
 * @defgroup unique_handle_aliases Aliases for UniqueHandle types
 * @brief Convenience names for specializations of UniqueHandle<>
 */
//! @}

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Instance
template <typename Dispatch> class UniqueHandleTraits<Instance, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Instance, using a static dispatch.
using UniqueInstance = UniqueHandle<Instance, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Instance, using a dynamic
//! dispatch.
using UniqueDynamicInstance = UniqueHandle<Instance, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrInstance
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrInstance>
//! @ingroup handles
class Instance {
public:
  using Type = Instance;
  using RawHandleType = XrInstance;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Instance() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Instance(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrInstance type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Instance(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrInstance
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrInstance type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Instance yourHandle;
  //! auto result = d.xrCreateInstance(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetInstanceProcAddr wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProcAddr>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrGetInstanceProcAddr wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProcAddr>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroyInstance wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyInstance>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroyInstance wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyInstance>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetInstanceProperties wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getInstanceProperties(InstanceProperties &instanceProperties,
                               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetInstanceProperties wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<InstanceProperties>::type
  getInstanceProperties(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrPollEvent wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPollEvent>

  template <typename Dispatch = DispatchLoaderStatic>
  Result pollEvent(EventDataBuffer &eventData, Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrPollEvent wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPollEvent>

  template <typename Dispatch = DispatchLoaderStatic>
  Result pollEvent(EventDataBuffer &eventData, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrResultToString wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrResultToString>

  template <typename Dispatch = DispatchLoaderStatic>
  Result resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                        Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrResultToString wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrResultToString>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                 Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrStructureTypeToString wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStructureTypeToString>

  template <typename Dispatch = DispatchLoaderStatic>
  Result structureTypeToString(StructureType value,
                               char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrStructureTypeToString wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStructureTypeToString>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  structureTypeToString(StructureType value,
                        char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

  //! @brief xrGetSystem wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystem>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getSystem(const SystemGetInfo &getInfo, XrSystemId *systemId,
                   Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetSystem wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystem>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<SystemId>::type
  getSystem(const SystemGetInfo &getInfo, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetSystemProperties wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystemProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getSystemProperties(XrSystemId systemId, SystemProperties &properties,
                             Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetSystemProperties wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystemProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<SystemProperties>::type
  getSystemProperties(XrSystemId systemId, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateEnvironmentBlendModes wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateEnvironmentBlendModes>

  template <typename Dispatch = DispatchLoaderStatic>
  Result
  enumerateEnvironmentBlendModes(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 uint32_t environmentBlendModeCapacityInput,
                                 uint32_t *environmentBlendModeCountOutput,
                                 XrEnvironmentBlendMode *environmentBlendModes,
                                 Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateEnvironmentBlendModes wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateEnvironmentBlendModes>

  template <typename Allocator = ::std::allocator<EnvironmentBlendMode>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<EnvironmentBlendMode, Allocator>>::type
  enumerateEnvironmentBlendModes(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateEnvironmentBlendModes wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateEnvironmentBlendModes>

  template <typename Allocator = ::std::allocator<EnvironmentBlendMode>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<EnvironmentBlendMode, Allocator>>::type
  enumerateEnvironmentBlendModes(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 Allocator const &vectorAllocator,
                                 Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateSession wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createSession(const SessionCreateInfo &createInfo, Session &session,
                       Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateSession wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Session>::type
  createSession(const SessionCreateInfo &createInfo,
                Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateSession wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Session, impl::RemoveRefConst<Dispatch>>>::type
  createSessionUnique(const SessionCreateInfo &createInfo,
                      Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateViewConfigurations wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurations>

  template <typename Dispatch = DispatchLoaderStatic>
  Result
  enumerateViewConfigurations(XrSystemId systemId,
                              uint32_t viewConfigurationTypeCapacityInput,
                              uint32_t *viewConfigurationTypeCountOutput,
                              XrViewConfigurationType *viewConfigurationTypes,
                              Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateViewConfigurations wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurations>

  template <typename Allocator = ::std::allocator<ViewConfigurationType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::vector<ViewConfigurationType, Allocator>>::type
  enumerateViewConfigurations(XrSystemId systemId,
                              Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateViewConfigurations wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurations>

  template <typename Allocator = ::std::allocator<ViewConfigurationType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::vector<ViewConfigurationType, Allocator>>::type
  enumerateViewConfigurations(XrSystemId systemId,
                              Allocator const &vectorAllocator,
                              Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetViewConfigurationProperties wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetViewConfigurationProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getViewConfigurationProperties(
      XrSystemId systemId, ViewConfigurationType viewConfigurationType,
      ViewConfigurationProperties &configurationProperties,
      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetViewConfigurationProperties wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetViewConfigurationProperties>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ViewConfigurationProperties>::type
  getViewConfigurationProperties(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateViewConfigurationViews wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>

  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateViewConfigurationViews(
      XrSystemId systemId, ViewConfigurationType viewConfigurationType,
      uint32_t viewCapacityInput, uint32_t *viewCountOutput,
      XrViewConfigurationView *views, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateViewConfigurationViews wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>

  template <typename Allocator = ::std::allocator<ViewConfigurationView>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::vector<ViewConfigurationView, Allocator>>::type
  enumerateViewConfigurationViews(XrSystemId systemId,
                                  ViewConfigurationType viewConfigurationType,
                                  Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateViewConfigurationViews wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>

  template <typename Allocator = ::std::allocator<ViewConfigurationView>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::vector<ViewConfigurationView, Allocator>>::type
  enumerateViewConfigurationViews(XrSystemId systemId,
                                  ViewConfigurationType viewConfigurationType,
                                  Allocator const &vectorAllocator,
                                  Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrStringToPath wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStringToPath>

  template <typename Dispatch = DispatchLoaderStatic>
  Result stringToPath(const char *pathString, XrPath *path,
                      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrStringToPath wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStringToPath>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Path>::type
  stringToPath(const char *pathString, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrPathToString wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>

  template <typename Dispatch = DispatchLoaderStatic>
  Result pathToString(XrPath path, uint32_t bufferCapacityInput,
                      uint32_t *bufferCountOutput, char *buffer,
                      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrPathToString wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>

  template <typename Allocator = ::std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  pathToString(XrPath path, Dispatch &&d = Dispatch{}) const;

  //! @brief xrPathToString wrapper - enhanced mode, stateful allocator for
  //! two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>

  template <typename Allocator = ::std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  pathToString(XrPath path, Allocator const &vectorAllocator,
               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateActionSet wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createActionSet(const ActionSetCreateInfo &createInfo,
                         ActionSet &actionSet, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateActionSet wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionSet>::type
  createActionSet(const ActionSetCreateInfo &createInfo,
                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateActionSet wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<ActionSet, impl::RemoveRefConst<Dispatch>>>::type
  createActionSetUnique(const ActionSetCreateInfo &createInfo,
                        Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSuggestInteractionProfileBindings wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSuggestInteractionProfileBindings>

  template <typename Dispatch = DispatchLoaderStatic>
  Result suggestInteractionProfileBindings(
      const InteractionProfileSuggestedBinding &suggestedBindings,
      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSuggestInteractionProfileBindings wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSuggestInteractionProfileBindings>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type suggestInteractionProfileBindings(
      const InteractionProfileSuggestedBinding &suggestedBindings,
      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_GRAPHICS_API_OPENGL)

  //! @brief xrGetOpenGLGraphicsRequirementsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getOpenGLGraphicsRequirementsKHR(
      XrSystemId systemId, GraphicsRequirementsOpenGLKHR &graphicsRequirements,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetOpenGLGraphicsRequirementsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<GraphicsRequirementsOpenGLKHR>::type
  getOpenGLGraphicsRequirementsKHR(XrSystemId systemId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)

  //! @brief xrGetOpenGLESGraphicsRequirementsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLESGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getOpenGLESGraphicsRequirementsKHR(
      XrSystemId systemId,
      GraphicsRequirementsOpenGLESKHR &graphicsRequirements,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetOpenGLESGraphicsRequirementsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLESGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<GraphicsRequirementsOpenGLESKHR>::type
  getOpenGLESGraphicsRequirementsKHR(XrSystemId systemId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  //! @brief xrGetVulkanInstanceExtensionsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                        uint32_t bufferCapacityInput,
                                        uint32_t *bufferCountOutput,
                                        char *buffer, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetVulkanInstanceExtensionsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Allocator = ::std::allocator<char>, typename Dispatch>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getVulkanInstanceExtensionsKHR(XrSystemId systemId, Dispatch &&d) const;

  //! @brief xrGetVulkanInstanceExtensionsKHR wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Allocator = ::std::allocator<char>, typename Dispatch>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                 Allocator const &vectorAllocator,
                                 Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  //! @brief xrGetVulkanDeviceExtensionsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                      uint32_t bufferCapacityInput,
                                      uint32_t *bufferCountOutput, char *buffer,
                                      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetVulkanDeviceExtensionsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Allocator = ::std::allocator<char>, typename Dispatch>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getVulkanDeviceExtensionsKHR(XrSystemId systemId, Dispatch &&d) const;

  //! @brief xrGetVulkanDeviceExtensionsKHR wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Allocator = ::std::allocator<char>, typename Dispatch>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                               Allocator const &vectorAllocator,
                               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  //! @brief xrGetVulkanGraphicsDeviceKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsDeviceKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                                    VkPhysicalDevice *vkPhysicalDevice,
                                    Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetVulkanGraphicsDeviceKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsDeviceKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<VkPhysicalDevice>::type
  getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                             Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  //! @brief xrGetVulkanGraphicsRequirementsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getVulkanGraphicsRequirementsKHR(
      XrSystemId systemId, GraphicsRequirementsVulkanKHR &graphicsRequirements,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetVulkanGraphicsRequirementsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<GraphicsRequirementsVulkanKHR>::type
  getVulkanGraphicsRequirementsKHR(XrSystemId systemId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)

  //! @brief xrGetD3D11GraphicsRequirementsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D11GraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getD3D11GraphicsRequirementsKHR(
      XrSystemId systemId, GraphicsRequirementsD3D11KHR &graphicsRequirements,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetD3D11GraphicsRequirementsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D11GraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<GraphicsRequirementsD3D11KHR>::type
  getD3D11GraphicsRequirementsKHR(XrSystemId systemId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)

  //! @brief xrGetD3D12GraphicsRequirementsKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D12GraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getD3D12GraphicsRequirementsKHR(
      XrSystemId systemId, GraphicsRequirementsD3D12KHR &graphicsRequirements,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetD3D12GraphicsRequirementsKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D12GraphicsRequirementsKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<GraphicsRequirementsD3D12KHR>::type
  getD3D12GraphicsRequirementsKHR(XrSystemId systemId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D12)

#if defined(XR_USE_PLATFORM_WIN32)

  //! @brief xrConvertWin32PerformanceCounterToTimeKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertWin32PerformanceCounterToTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result convertWin32PerformanceCounterToTimeKHR(
      const LARGE_INTEGER *performanceCounter, XrTime *time,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrConvertWin32PerformanceCounterToTimeKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertWin32PerformanceCounterToTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<Time>::type convertWin32PerformanceCounterToTimeKHR(
      const LARGE_INTEGER *performanceCounter, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)

  //! @brief xrConvertTimeToWin32PerformanceCounterKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToWin32PerformanceCounterKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result convertTimeToWin32PerformanceCounterKHR(
      XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrConvertTimeToWin32PerformanceCounterKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToWin32PerformanceCounterKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<LARGE_INTEGER>::type
  convertTimeToWin32PerformanceCounterKHR(XrTime time, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)

  //! @brief xrConvertTimespecTimeToTimeKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimespecTimeToTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                                      XrTime *time, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrConvertTimespecTimeToTimeKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimespecTimeToTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<Time>::type
  convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)

  //! @brief xrConvertTimeToTimespecTimeKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToTimespecTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result convertTimeToTimespecTimeKHR(XrTime time,
                                      struct timespec *timespecTime,
                                      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrConvertTimeToTimespecTimeKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToTimespecTimeKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<timespec>::type
  convertTimeToTimespecTimeKHR(XrTime time, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSetDebugUtilsObjectNameEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetDebugUtilsObjectNameEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result setDebugUtilsObjectNameEXT(const DebugUtilsObjectNameInfoEXT &nameInfo,
                                    Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSetDebugUtilsObjectNameEXT wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetDebugUtilsObjectNameEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  setDebugUtilsObjectNameEXT(const DebugUtilsObjectNameInfoEXT &nameInfo,
                             Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateDebugUtilsMessengerEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result createDebugUtilsMessengerEXT(
      const DebugUtilsMessengerCreateInfoEXT &createInfo,
      DebugUtilsMessengerEXT &messenger, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateDebugUtilsMessengerEXT wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<DebugUtilsMessengerEXT>::type
  createDebugUtilsMessengerEXT(
      const DebugUtilsMessengerCreateInfoEXT &createInfo, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateDebugUtilsMessengerEXT wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<UniqueHandle<DebugUtilsMessengerEXT,
                                        impl::RemoveRefConst<Dispatch>>>::type
  createDebugUtilsMessengerUniqueEXT(
      const DebugUtilsMessengerCreateInfoEXT &createInfo, Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSubmitDebugUtilsMessageEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSubmitDebugUtilsMessageEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result submitDebugUtilsMessageEXT(
      XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const DebugUtilsMessengerCallbackDataEXT &callbackData,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSubmitDebugUtilsMessageEXT wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSubmitDebugUtilsMessageEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type submitDebugUtilsMessageEXT(
      XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const DebugUtilsMessengerCallbackDataEXT &callbackData,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Instance) == sizeof(XrInstance),
              "handle and wrapper have different size!");

//! @brief < comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Instance const &lhs,
                                                      Instance const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Instance const &lhs,
                                                      XrInstance rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrInstance lhs,
                                                      Instance const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Instance const &lhs,
                                                      Instance const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Instance const &lhs,
                                                      XrInstance rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrInstance lhs,
                                                      Instance const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Instance and nullptr: true if the handle
//! is null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Instance const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Instance: true if the handle
//! is null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Instance const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Instance and nullptr: true if the
//! handle is not null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Instance const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Instance: true if the
//! handle is not null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Instance const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrInstance handle in a Instance
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrInstance get(Instance const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrInstance handle in a Instance (by reference).
//!
//! e.g.
//! ```
//! Instance yourHandle;
//! auto result = d.xrCreateInstance(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Instance
OPENXR_HPP_INLINE XrInstance *put(Instance &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrInstance handle in a Instance (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Instance* yourHandle) {
//!     auto result = d.xrCreateInstance(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Instance
OPENXR_HPP_INLINE XrInstance *put(Instance *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Instance
template <> struct cpp_type<ObjectType::Instance> { using type = Instance; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Session
template <typename Dispatch> class UniqueHandleTraits<Session, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Session, using a static dispatch.
using UniqueSession = UniqueHandle<Session, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Session, using a dynamic dispatch.
using UniqueDynamicSession = UniqueHandle<Session, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSession
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSession>
//! @ingroup handles
class Session {
public:
  using Type = Session;
  using RawHandleType = XrSession;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Session() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Session(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSession type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Session(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSession
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSession type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Session yourHandle;
  //! auto result = d.xrCreateSession(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroySession wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySession>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroySession wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySession>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateReferenceSpaces wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>

  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateReferenceSpaces(uint32_t spaceCapacityInput,
                                  uint32_t *spaceCountOutput,
                                  XrReferenceSpaceType *spaces,
                                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateReferenceSpaces wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>

  template <typename Allocator = ::std::allocator<ReferenceSpaceType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<ReferenceSpaceType, Allocator>>::type
  enumerateReferenceSpaces(Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateReferenceSpaces wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>

  template <typename Allocator = ::std::allocator<ReferenceSpaceType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<ReferenceSpaceType, Allocator>>::type
  enumerateReferenceSpaces(Allocator const &vectorAllocator,
                           Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateReferenceSpace wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createReferenceSpace(const ReferenceSpaceCreateInfo &createInfo,
                              Space &space, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateReferenceSpace wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Space>::type
  createReferenceSpace(const ReferenceSpaceCreateInfo &createInfo,
                       Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateReferenceSpace wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
  createReferenceSpaceUnique(const ReferenceSpaceCreateInfo &createInfo,
                             Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetReferenceSpaceBoundsRect wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetReferenceSpaceBoundsRect>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     Extent2Df &bounds,
                                     Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrGetReferenceSpaceBoundsRect wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetReferenceSpaceBoundsRect>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     Extent2Df &bounds,
                                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateActionSpace wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createActionSpace(const ActionSpaceCreateInfo &createInfo,
                           Space &space, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateActionSpace wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Space>::type
  createActionSpace(const ActionSpaceCreateInfo &createInfo,
                    Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateActionSpace wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
  createActionSpaceUnique(const ActionSpaceCreateInfo &createInfo,
                          Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateSwapchainFormats wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>

  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateSwapchainFormats(uint32_t formatCapacityInput,
                                   uint32_t *formatCountOutput,
                                   int64_t *formats,
                                   Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateSwapchainFormats wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>

  template <typename Allocator = ::std::allocator<int64_t>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<int64_t, Allocator>>::type
  enumerateSwapchainFormats(Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateSwapchainFormats wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>

  template <typename Allocator = ::std::allocator<int64_t>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<int64_t, Allocator>>::type
  enumerateSwapchainFormats(Allocator const &vectorAllocator,
                            Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateSwapchain wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createSwapchain(const SwapchainCreateInfo &createInfo,
                         Swapchain &swapchain, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateSwapchain wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Swapchain>::type
  createSwapchain(const SwapchainCreateInfo &createInfo,
                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateSwapchain wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>>::type
  createSwapchainUnique(const SwapchainCreateInfo &createInfo,
                        Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrBeginSession wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginSession>

  template <typename Dispatch = DispatchLoaderStatic>
  Result beginSession(const SessionBeginInfo &beginInfo,
                      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrBeginSession wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginSession>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type beginSession(const SessionBeginInfo &beginInfo,
                                           Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEndSession wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndSession>

  template <typename Dispatch = DispatchLoaderStatic>
  Result endSession(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrEndSession wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndSession>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type endSession(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrRequestExitSession wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrRequestExitSession>

  template <typename Dispatch = DispatchLoaderStatic>
  Result requestExitSession(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrRequestExitSession wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrRequestExitSession>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  requestExitSession(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrWaitFrame wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  Result waitFrame(const FrameWaitInfo &frameWaitInfo, FrameState &frameState,
                   Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrWaitFrame wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<FrameState>::type
  waitFrame(const FrameWaitInfo &frameWaitInfo,
            Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrBeginFrame wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  Result beginFrame(const FrameBeginInfo &frameBeginInfo,
                    Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrBeginFrame wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  Result beginFrame(const FrameBeginInfo &frameBeginInfo,
                    Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEndFrame wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  Result endFrame(const FrameEndInfo &frameEndInfo,
                  Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrEndFrame wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndFrame>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type endFrame(const FrameEndInfo &frameEndInfo,
                                       Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrLocateViews wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>

  template <typename Dispatch = DispatchLoaderStatic>
  Result locateViews(const ViewLocateInfo &viewLocateInfo,
                     XrViewState *viewState, uint32_t viewCapacityInput,
                     uint32_t *viewCountOutput, XrView *views,
                     Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrLocateViews wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>

  template <typename Allocator = ::std::allocator<View>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<View, Allocator>>::type
  locateViews(const ViewLocateInfo &viewLocateInfo, XrViewState *viewState,
              Dispatch &&d = Dispatch{}) const;

  //! @brief xrLocateViews wrapper - enhanced mode, stateful allocator for
  //! two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>

  template <typename Allocator = ::std::allocator<View>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<View, Allocator>>::type
  locateViews(const ViewLocateInfo &viewLocateInfo, XrViewState *viewState,
              Allocator const &vectorAllocator, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrAttachSessionActionSets wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAttachSessionActionSets>

  template <typename Dispatch = DispatchLoaderStatic>
  Result attachSessionActionSets(const SessionActionSetsAttachInfo &attachInfo,
                                 Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrAttachSessionActionSets wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAttachSessionActionSets>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  attachSessionActionSets(const SessionActionSetsAttachInfo &attachInfo,
                          Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetCurrentInteractionProfile wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetCurrentInteractionProfile>

  template <typename Dispatch = DispatchLoaderStatic>
  Result
  getCurrentInteractionProfile(XrPath topLevelUserPath,
                               InteractionProfileState &interactionProfile,
                               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetCurrentInteractionProfile wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetCurrentInteractionProfile>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<InteractionProfileState>::type
  getCurrentInteractionProfile(XrPath topLevelUserPath,
                               Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetActionStateBoolean wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateBoolean>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateBoolean(const ActionStateGetInfo &getInfo,
                               ActionStateBoolean &state,
                               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetActionStateBoolean wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateBoolean>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionStateBoolean>::type
  getActionStateBoolean(const ActionStateGetInfo &getInfo,
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetActionStateFloat wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateFloat>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateFloat(const ActionStateGetInfo &getInfo,
                             ActionStateFloat &state,
                             Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetActionStateFloat wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateFloat>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionStateFloat>::type
  getActionStateFloat(const ActionStateGetInfo &getInfo,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetActionStateVector2f wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateVector2f>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateVector2f(const ActionStateGetInfo &getInfo,
                                ActionStateVector2f &state,
                                Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetActionStateVector2f wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateVector2f>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionStateVector2f>::type
  getActionStateVector2f(const ActionStateGetInfo &getInfo,
                         Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetActionStatePose wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStatePose>

  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStatePose(const ActionStateGetInfo &getInfo,
                            ActionStatePose &state,
                            Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetActionStatePose wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStatePose>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionStatePose>::type
  getActionStatePose(const ActionStateGetInfo &getInfo,
                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSyncActions wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSyncActions>

  template <typename Dispatch = DispatchLoaderStatic>
  Result syncActions(const ActionsSyncInfo &syncInfo,
                     Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSyncActions wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSyncActions>

  template <typename Dispatch = DispatchLoaderStatic>
  Result syncActions(const ActionsSyncInfo &syncInfo,
                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateBoundSourcesForAction wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>

  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateBoundSourcesForAction(
      const BoundSourcesForActionEnumerateInfo &enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateBoundSourcesForAction wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>

  template <typename Allocator = ::std::allocator<Path>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<Path, Allocator>>::type
  enumerateBoundSourcesForAction(
      const BoundSourcesForActionEnumerateInfo &enumerateInfo,
      Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateBoundSourcesForAction wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>

  template <typename Allocator = ::std::allocator<Path>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<Path, Allocator>>::type
  enumerateBoundSourcesForAction(
      const BoundSourcesForActionEnumerateInfo &enumerateInfo,
      Allocator const &vectorAllocator, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrGetInputSourceLocalizedName wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>

  template <typename Dispatch = DispatchLoaderStatic>
  Result
  getInputSourceLocalizedName(const InputSourceLocalizedNameGetInfo &getInfo,
                              uint32_t bufferCapacityInput,
                              uint32_t *bufferCountOutput, char *buffer,
                              Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetInputSourceLocalizedName wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>

  template <typename Allocator = ::std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getInputSourceLocalizedName(const InputSourceLocalizedNameGetInfo &getInfo,
                              Dispatch &&d = Dispatch{}) const;

  //! @brief xrGetInputSourceLocalizedName wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>

  template <typename Allocator = ::std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
  getInputSourceLocalizedName(const InputSourceLocalizedNameGetInfo &getInfo,
                              Allocator const &vectorAllocator,
                              Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrApplyHapticFeedback wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrApplyHapticFeedback>

  template <typename Dispatch = DispatchLoaderStatic>
  Result applyHapticFeedback(const HapticActionInfo &hapticActionInfo,
                             const XrHapticBaseHeader *hapticFeedback,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrApplyHapticFeedback wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrApplyHapticFeedback>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  applyHapticFeedback(const HapticActionInfo &hapticActionInfo,
                      const XrHapticBaseHeader *hapticFeedback,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrStopHapticFeedback wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStopHapticFeedback>

  template <typename Dispatch = DispatchLoaderStatic>
  Result stopHapticFeedback(const HapticActionInfo &hapticActionInfo,
                            Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrStopHapticFeedback wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStopHapticFeedback>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  stopHapticFeedback(const HapticActionInfo &hapticActionInfo,
                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_ANDROID)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSetAndroidApplicationThreadKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetAndroidApplicationThreadKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result setAndroidApplicationThreadKHR(AndroidThreadTypeKHR threadType,
                                        uint32_t threadId, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSetAndroidApplicationThreadKHR wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetAndroidApplicationThreadKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  setAndroidApplicationThreadKHR(AndroidThreadTypeKHR threadType,
                                 uint32_t threadId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)

  //! @brief xrCreateSwapchainAndroidSurfaceKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result createSwapchainAndroidSurfaceKHR(const SwapchainCreateInfo &info,
                                          Swapchain &swapchain,
                                          jobject *surface, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateSwapchainAndroidSurfaceKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<jobject>::type
  createSwapchainAndroidSurfaceKHR(const SwapchainCreateInfo &info,
                                   Swapchain &swapchain, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateSwapchainAndroidSurfaceKHR wrapper returning a smart
  //! handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<
      UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>>::type
  createSwapchainAndroidSurfaceUniqueKHR(const SwapchainCreateInfo &info,
                                         Swapchain &swapchain,
                                         Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

  //! @brief xrGetVisibilityMaskKHR wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVisibilityMaskKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result getVisibilityMaskKHR(ViewConfigurationType viewConfigurationType,
                              uint32_t viewIndex,
                              VisibilityMaskTypeKHR visibilityMaskType,
                              VisibilityMaskKHR &visibilityMask,
                              Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrGetVisibilityMaskKHR wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVisibilityMaskKHR>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<VisibilityMaskKHR>::type getVisibilityMaskKHR(
      ViewConfigurationType viewConfigurationType, uint32_t viewIndex,
      VisibilityMaskTypeKHR visibilityMaskType, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrPerfSettingsSetPerformanceLevelEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPerfSettingsSetPerformanceLevelEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result perfSettingsSetPerformanceLevelEXT(PerfSettingsDomainEXT domain,
                                            PerfSettingsLevelEXT level,
                                            Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrPerfSettingsSetPerformanceLevelEXT wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPerfSettingsSetPerformanceLevelEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  perfSettingsSetPerformanceLevelEXT(PerfSettingsDomainEXT domain,
                                     PerfSettingsLevelEXT level,
                                     Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrThermalGetTemperatureTrendEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrThermalGetTemperatureTrendEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result thermalGetTemperatureTrendEXT(
      PerfSettingsDomainEXT domain,
      PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
      float *tempSlope, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrThermalGetTemperatureTrendEXT wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrThermalGetTemperatureTrendEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type thermalGetTemperatureTrendEXT(
      PerfSettingsDomainEXT domain,
      PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
      float *tempSlope, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSessionBeginDebugUtilsLabelRegionEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionBeginDebugUtilsLabelRegionEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result
  sessionBeginDebugUtilsLabelRegionEXT(const DebugUtilsLabelEXT &labelInfo,
                                       Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSessionBeginDebugUtilsLabelRegionEXT wrapper - enhanced mode
  //! (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionBeginDebugUtilsLabelRegionEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  sessionBeginDebugUtilsLabelRegionEXT(const DebugUtilsLabelEXT &labelInfo,
                                       Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSessionEndDebugUtilsLabelRegionEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionEndDebugUtilsLabelRegionEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSessionEndDebugUtilsLabelRegionEXT wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionEndDebugUtilsLabelRegionEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrSessionInsertDebugUtilsLabelEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionInsertDebugUtilsLabelEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result sessionInsertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo,
                                         Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrSessionInsertDebugUtilsLabelEXT wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionInsertDebugUtilsLabelEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type
  sessionInsertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo,
                                  Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateSpatialAnchorMSFT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result createSpatialAnchorMSFT(const SpatialAnchorCreateInfoMSFT &createInfo,
                                 SpatialAnchorMSFT &anchor, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateSpatialAnchorMSFT wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<SpatialAnchorMSFT>::type
  createSpatialAnchorMSFT(const SpatialAnchorCreateInfoMSFT &createInfo,
                          Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateSpatialAnchorMSFT wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<
      UniqueHandle<SpatialAnchorMSFT, impl::RemoveRefConst<Dispatch>>>::type
  createSpatialAnchorUniqueMSFT(const SpatialAnchorCreateInfoMSFT &createInfo,
                                Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateSpatialAnchorSpaceMSFT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  Result createSpatialAnchorSpaceMSFT(
      const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Space &space,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateSpatialAnchorSpaceMSFT wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<Space>::type createSpatialAnchorSpaceMSFT(
      const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateSpatialAnchorSpaceMSFT wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  typename ResultValueType<
      UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
  createSpatialAnchorSpaceUniqueMSFT(
      const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Session) == sizeof(XrSession),
              "handle and wrapper have different size!");

//! @brief < comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Session const &lhs,
                                                      Session const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Session const &lhs,
                                                      XrSession rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSession lhs,
                                                      Session const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Session const &lhs,
                                                      Session const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Session const &lhs,
                                                      XrSession rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSession lhs,
                                                      Session const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSession lhs,
                                                       Session const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Session and nullptr: true if the handle
//! is null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Session const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Session: true if the handle
//! is null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Session const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Session and nullptr: true if the handle
//! is not null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Session const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Session: true if the handle
//! is not null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Session const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSession handle in a Session
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSession get(Session const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSession handle in a Session (by reference).
//!
//! e.g.
//! ```
//! Session yourHandle;
//! auto result = d.xrCreateSession(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Session
OPENXR_HPP_INLINE XrSession *put(Session &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSession handle in a Session (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Session* yourHandle) {
//!     auto result = d.xrCreateSession(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Session
OPENXR_HPP_INLINE XrSession *put(Session *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Session
template <> struct cpp_type<ObjectType::Session> { using type = Session; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Space
template <typename Dispatch> class UniqueHandleTraits<Space, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Space, using a static dispatch.
using UniqueSpace = UniqueHandle<Space, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Space, using a dynamic dispatch.
using UniqueDynamicSpace = UniqueHandle<Space, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSpace
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpace>
//! @ingroup handles
class Space {
public:
  using Type = Space;
  using RawHandleType = XrSpace;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Space() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Space(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSpace type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Space(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSpace
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSpace type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Space yourHandle;
  //! auto result = d.xrCreateSpace(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

  //! @brief xrLocateSpace wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  Result locateSpace(Space baseSpace, XrTime time, SpaceLocation &location,
                     Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrLocateSpace wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateSpace>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<SpaceLocation>::type
  locateSpace(Space baseSpace, XrTime time, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroySpace wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpace>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroySpace wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpace>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Space) == sizeof(XrSpace),
              "handle and wrapper have different size!");

//! @brief < comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Space const &lhs,
                                                      Space const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Space const &lhs,
                                                      XrSpace rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSpace lhs,
                                                      Space const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Space const &lhs,
                                                      Space const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Space const &lhs,
                                                      XrSpace rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSpace lhs,
                                                      Space const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Space and nullptr: true if the handle is
//! null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Space const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Space: true if the handle is
//! null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Space const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Space and nullptr: true if the handle
//! is not null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Space const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Space: true if the handle
//! is not null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Space const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSpace handle in a Space
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSpace get(Space const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpace handle in a Space (by reference).
//!
//! e.g.
//! ```
//! Space yourHandle;
//! auto result = d.xrCreateSpace(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Space
OPENXR_HPP_INLINE XrSpace *put(Space &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpace handle in a Space (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Space* yourHandle) {
//!     auto result = d.xrCreateSpace(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Space
OPENXR_HPP_INLINE XrSpace *put(Space *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Space
template <> struct cpp_type<ObjectType::Space> { using type = Space; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Action
template <typename Dispatch> class UniqueHandleTraits<Action, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Action, using a static dispatch.
using UniqueAction = UniqueHandle<Action, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Action, using a dynamic dispatch.
using UniqueDynamicAction = UniqueHandle<Action, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrAction
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrAction>
//! @ingroup handles
class Action {
public:
  using Type = Action;
  using RawHandleType = XrAction;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Action() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Action(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrAction type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Action(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrAction
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrAction type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Action yourHandle;
  //! auto result = d.xrCreateAction(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroyAction wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyAction>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroyAction wrapper - enhanced mode (hides basic wrapper unless
  //! OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyAction>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Action) == sizeof(XrAction),
              "handle and wrapper have different size!");

//! @brief < comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Action const &lhs,
                                                      Action const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Action const &lhs,
                                                      XrAction rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrAction lhs,
                                                      Action const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Action const &lhs,
                                                      Action const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Action const &lhs,
                                                      XrAction rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrAction lhs,
                                                      Action const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrAction lhs,
                                                       Action const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Action and nullptr: true if the handle is
//! null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Action const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Action: true if the handle is
//! null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Action const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Action and nullptr: true if the handle
//! is not null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Action const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Action: true if the handle
//! is not null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Action const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrAction handle in a Action
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrAction get(Action const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrAction handle in a Action (by reference).
//!
//! e.g.
//! ```
//! Action yourHandle;
//! auto result = d.xrCreateAction(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Action
OPENXR_HPP_INLINE XrAction *put(Action &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrAction handle in a Action (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Action* yourHandle) {
//!     auto result = d.xrCreateAction(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Action
OPENXR_HPP_INLINE XrAction *put(Action *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Action
template <> struct cpp_type<ObjectType::Action> { using type = Action; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Swapchain
template <typename Dispatch> class UniqueHandleTraits<Swapchain, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Swapchain, using a static
//! dispatch.
using UniqueSwapchain = UniqueHandle<Swapchain, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Swapchain, using a dynamic
//! dispatch.
using UniqueDynamicSwapchain = UniqueHandle<Swapchain, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSwapchain
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSwapchain>
//! @ingroup handles
class Swapchain {
public:
  using Type = Swapchain;
  using RawHandleType = XrSwapchain;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Swapchain() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Swapchain(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSwapchain type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Swapchain(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSwapchain
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSwapchain type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Swapchain yourHandle;
  //! auto result = d.xrCreateSwapchain(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroySwapchain wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySwapchain>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroySwapchain wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySwapchain>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrEnumerateSwapchainImages wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainImages>

  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateSwapchainImages(uint32_t imageCapacityInput,
                                  uint32_t *imageCountOutput,
                                  XrSwapchainImageBaseHeader *images,
                                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrEnumerateSwapchainImages wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainImages>

  template <typename ResultItemType,
            typename Allocator = ::std::allocator<ResultItemType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<ResultItemType, Allocator>>::type
  enumerateSwapchainImages(Dispatch &&d = Dispatch{}) const;

  //! @brief xrEnumerateSwapchainImages wrapper - enhanced mode, stateful
  //! allocator for two-call result.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainImages>

  template <typename ResultItemType,
            typename Allocator = ::std::allocator<ResultItemType>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<::std::vector<ResultItemType, Allocator>>::type
  enumerateSwapchainImages(Allocator const &vectorAllocator,
                           Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrAcquireSwapchainImage wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAcquireSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  Result acquireSwapchainImage(const SwapchainImageAcquireInfo &acquireInfo,
                               uint32_t *index,
                               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrAcquireSwapchainImage wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAcquireSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<uint32_t>::type
  acquireSwapchainImage(const SwapchainImageAcquireInfo &acquireInfo,
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrWaitSwapchainImage wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  Result waitSwapchainImage(const SwapchainImageWaitInfo &waitInfo,
                            Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrWaitSwapchainImage wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  Result waitSwapchainImage(const SwapchainImageWaitInfo &waitInfo,
                            Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrReleaseSwapchainImage wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrReleaseSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  Result releaseSwapchainImage(const SwapchainImageReleaseInfo &releaseInfo,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrReleaseSwapchainImage wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrReleaseSwapchainImage>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  releaseSwapchainImage(const SwapchainImageReleaseInfo &releaseInfo,
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Swapchain) == sizeof(XrSwapchain),
              "handle and wrapper have different size!");

//! @brief < comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Swapchain const &lhs,
                                                      Swapchain const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Swapchain const &lhs,
                                                      XrSwapchain rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSwapchain lhs,
                                                      Swapchain const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Swapchain const &lhs,
                                                      Swapchain const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Swapchain const &lhs,
                                                      XrSwapchain rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSwapchain lhs,
                                                      Swapchain const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Swapchain and nullptr: true if the handle
//! is null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Swapchain const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Swapchain: true if the handle
//! is null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Swapchain const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Swapchain and nullptr: true if the
//! handle is not null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Swapchain const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Swapchain: true if the
//! handle is not null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Swapchain const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSwapchain handle in a Swapchain
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSwapchain get(Swapchain const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSwapchain handle in a Swapchain (by reference).
//!
//! e.g.
//! ```
//! Swapchain yourHandle;
//! auto result = d.xrCreateSwapchain(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Swapchain
OPENXR_HPP_INLINE XrSwapchain *put(Swapchain &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSwapchain handle in a Swapchain (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Swapchain* yourHandle) {
//!     auto result = d.xrCreateSwapchain(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Swapchain
OPENXR_HPP_INLINE XrSwapchain *put(Swapchain *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Swapchain
template <> struct cpp_type<ObjectType::Swapchain> { using type = Swapchain; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type ActionSet
template <typename Dispatch> class UniqueHandleTraits<ActionSet, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type ActionSet, using a static
//! dispatch.
using UniqueActionSet = UniqueHandle<ActionSet, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type ActionSet, using a dynamic
//! dispatch.
using UniqueDynamicActionSet = UniqueHandle<ActionSet, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrActionSet
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrActionSet>
//! @ingroup handles
class ActionSet {
public:
  using Type = ActionSet;
  using RawHandleType = XrActionSet;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR ActionSet() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR ActionSet(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrActionSet type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT ActionSet(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrActionSet
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrActionSet type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! ActionSet yourHandle;
  //! auto result = d.xrCreateActionSet(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroyActionSet wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyActionSet>

  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroyActionSet wrapper - enhanced mode (hides basic wrapper
  //! unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyActionSet>

  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @brief xrCreateAction wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>

  template <typename Dispatch = DispatchLoaderStatic>
  Result createAction(const ActionCreateInfo &createInfo, Action &action,
                      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrCreateAction wrapper - enhanced mode.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Action>::type
  createAction(const ActionCreateInfo &createInfo,
               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  //! @brief xrCreateAction wrapper returning a smart handle.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>

  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Action, impl::RemoveRefConst<Dispatch>>>::type
  createActionUnique(const ActionCreateInfo &createInfo,
                     Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(ActionSet) == sizeof(XrActionSet),
              "handle and wrapper have different size!");

//! @brief < comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(ActionSet const &lhs,
                                                      ActionSet const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(ActionSet const &lhs,
                                                      XrActionSet rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrActionSet lhs,
                                                      ActionSet const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(ActionSet const &lhs,
                                                      ActionSet const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(ActionSet const &lhs,
                                                      XrActionSet rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrActionSet lhs,
                                                      ActionSet const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between ActionSet and nullptr: true if the handle
//! is null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(ActionSet const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and ActionSet: true if the handle
//! is null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, ActionSet const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between ActionSet and nullptr: true if the
//! handle is not null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(ActionSet const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and ActionSet: true if the
//! handle is not null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, ActionSet const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrActionSet handle in a ActionSet
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrActionSet get(ActionSet const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrActionSet handle in a ActionSet (by reference).
//!
//! e.g.
//! ```
//! ActionSet yourHandle;
//! auto result = d.xrCreateActionSet(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates ActionSet
OPENXR_HPP_INLINE XrActionSet *put(ActionSet &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrActionSet handle in a ActionSet (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(ActionSet* yourHandle) {
//!     auto result = d.xrCreateActionSet(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates ActionSet
OPENXR_HPP_INLINE XrActionSet *put(ActionSet *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for ActionSet
template <> struct cpp_type<ObjectType::ActionSet> { using type = ActionSet; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type
//! DebugUtilsMessengerEXT
template <typename Dispatch>
class UniqueHandleTraits<DebugUtilsMessengerEXT, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type DebugUtilsMessengerEXT, using a
//! static dispatch.
using UniqueDebugUtilsMessengerEXT =
    UniqueHandle<DebugUtilsMessengerEXT, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type DebugUtilsMessengerEXT, using a
//! dynamic dispatch.
using UniqueDynamicDebugUtilsMessengerEXT =
    UniqueHandle<DebugUtilsMessengerEXT, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrDebugUtilsMessengerEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrDebugUtilsMessengerEXT>
//! @ingroup handles
class DebugUtilsMessengerEXT {
public:
  using Type = DebugUtilsMessengerEXT;
  using RawHandleType = XrDebugUtilsMessengerEXT;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR DebugUtilsMessengerEXT() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR DebugUtilsMessengerEXT(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrDebugUtilsMessengerEXT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT DebugUtilsMessengerEXT(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrDebugUtilsMessengerEXT
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrDebugUtilsMessengerEXT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! DebugUtilsMessengerEXT yourHandle;
  //! auto result = d.xrCreateDebugUtilsMessengerEXT(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroyDebugUtilsMessengerEXT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyDebugUtilsMessengerEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch> Result destroy(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroyDebugUtilsMessengerEXT wrapper - enhanced mode (hides
  //! basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyDebugUtilsMessengerEXT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type destroy(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(DebugUtilsMessengerEXT) ==
                  sizeof(XrDebugUtilsMessengerEXT),
              "handle and wrapper have different size!");

//! @brief < comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(DebugUtilsMessengerEXT const &lhs,
          DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(DebugUtilsMessengerEXT const &lhs,
          DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between DebugUtilsMessengerEXT and nullptr: true
//! if the handle is null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and DebugUtilsMessengerEXT: true
//! if the handle is null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, DebugUtilsMessengerEXT const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between DebugUtilsMessengerEXT and nullptr:
//! true if the handle is not null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and DebugUtilsMessengerEXT:
//! true if the handle is not null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, DebugUtilsMessengerEXT const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrDebugUtilsMessengerEXT handle in
//! a DebugUtilsMessengerEXT
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT
get(DebugUtilsMessengerEXT const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrDebugUtilsMessengerEXT handle in a DebugUtilsMessengerEXT (by reference).
//!
//! e.g.
//! ```
//! DebugUtilsMessengerEXT yourHandle;
//! auto result = d.xrCreateDebugUtilsMessengerEXT(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT *put(DebugUtilsMessengerEXT &h) {
  return h.put();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrDebugUtilsMessengerEXT handle in a DebugUtilsMessengerEXT (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(DebugUtilsMessengerEXT* yourHandle) {
//!     auto result = d.xrCreateDebugUtilsMessengerEXT(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT *put(DebugUtilsMessengerEXT *h) {
  return h->put();
}

namespace traits {
//! @brief Explicit specialization of cpp_type for DebugUtilsMessengerEXT
template <> struct cpp_type<ObjectType::DebugUtilsMessengerEXT> {
  using type = DebugUtilsMessengerEXT;
};
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type SpatialAnchorMSFT
template <typename Dispatch>
class UniqueHandleTraits<SpatialAnchorMSFT, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type SpatialAnchorMSFT, using a static
//! dispatch.
using UniqueSpatialAnchorMSFT =
    UniqueHandle<SpatialAnchorMSFT, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type SpatialAnchorMSFT, using a dynamic
//! dispatch.
using UniqueDynamicSpatialAnchorMSFT =
    UniqueHandle<SpatialAnchorMSFT, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSpatialAnchorMSFT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpatialAnchorMSFT>
//! @ingroup handles
class SpatialAnchorMSFT {
public:
  using Type = SpatialAnchorMSFT;
  using RawHandleType = XrSpatialAnchorMSFT;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR SpatialAnchorMSFT() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR SpatialAnchorMSFT(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSpatialAnchorMSFT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT SpatialAnchorMSFT(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSpatialAnchorMSFT
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSpatialAnchorMSFT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! SpatialAnchorMSFT yourHandle;
  //! auto result = d.xrCreateSpatialAnchorMSFT(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  //! @brief xrDestroySpatialAnchorMSFT wrapper.
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpatialAnchorMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch> Result destroy(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  //! @brief xrDestroySpatialAnchorMSFT wrapper - enhanced mode (hides basic
  //! wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
  //!
  //! See the related specification text at
  //! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpatialAnchorMSFT>
  //!
  //! @note No default dispatch is provided as this is a non-core function,
  //! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
  template <typename Dispatch>
  ResultValueType<void>::type destroy(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(SpatialAnchorMSFT) == sizeof(XrSpatialAnchorMSFT),
              "handle and wrapper have different size!");

//! @brief < comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between SpatialAnchorMSFT and nullptr: true if
//! the handle is null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and SpatialAnchorMSFT: true if
//! the handle is null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, SpatialAnchorMSFT const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between SpatialAnchorMSFT and nullptr: true if
//! the handle is not null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and SpatialAnchorMSFT: true if
//! the handle is not null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, SpatialAnchorMSFT const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSpatialAnchorMSFT handle in a
//! SpatialAnchorMSFT
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSpatialAnchorMSFT
get(SpatialAnchorMSFT const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpatialAnchorMSFT handle in a SpatialAnchorMSFT (by reference).
//!
//! e.g.
//! ```
//! SpatialAnchorMSFT yourHandle;
//! auto result = d.xrCreateSpatialAnchorMSFT(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_INLINE XrSpatialAnchorMSFT *put(SpatialAnchorMSFT &h) {
  return h.put();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpatialAnchorMSFT handle in a SpatialAnchorMSFT (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(SpatialAnchorMSFT* yourHandle) {
//!     auto result = d.xrCreateSpatialAnchorMSFT(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_INLINE XrSpatialAnchorMSFT *put(SpatialAnchorMSFT *h) {
  return h->put();
}

namespace traits {
//! @brief Explicit specialization of cpp_type for SpatialAnchorMSFT
template <> struct cpp_type<ObjectType::SpatialAnchorMSFT> {
  using type = SpatialAnchorMSFT;
};
} // namespace traits

/*!
 * @defgroup api_free_functions OpenXR API free functions
 *
 * Equivalent to the method wrappers in the handle classes,
 * but for the few functions that don't take (or don't require)
 * a handle as their first argument.
 * @{
 */
// Forward declarations - implementations at the bottom of the file

//! @brief xrEnumerateApiLayerProperties wrapper.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>

template <typename Dispatch = DispatchLoaderStatic>
Result enumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                   uint32_t *propertyCountOutput,
                                   XrApiLayerProperties *properties,
                                   Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//! @brief xrEnumerateApiLayerProperties wrapper - enhanced mode.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>

template <typename Allocator = ::std::allocator<ApiLayerProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<::std::vector<ApiLayerProperties, Allocator>>::type
enumerateApiLayerProperties(Dispatch &&d = Dispatch{});

//! @brief xrEnumerateApiLayerProperties wrapper - enhanced mode, stateful
//! allocator for two-call result.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>

template <typename Allocator = ::std::allocator<ApiLayerProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<::std::vector<ApiLayerProperties, Allocator>>::type
enumerateApiLayerProperties(Allocator const &vectorAllocator, Dispatch &&d);

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

//! @brief xrEnumerateInstanceExtensionProperties wrapper.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>

template <typename Dispatch = DispatchLoaderStatic>
Result enumerateInstanceExtensionProperties(const char *layerName,
                                            uint32_t propertyCapacityInput,
                                            uint32_t *propertyCountOutput,
                                            XrExtensionProperties *properties,
                                            Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//! @brief xrEnumerateInstanceExtensionProperties wrapper - enhanced mode.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>

template <typename Allocator = ::std::allocator<ExtensionProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<::std::vector<ExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Dispatch &&d = Dispatch{});

//! @brief xrEnumerateInstanceExtensionProperties wrapper - enhanced mode,
//! stateful allocator for two-call result.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>

template <typename Allocator = ::std::allocator<ExtensionProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<::std::vector<ExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Allocator const &vectorAllocator,
                                     Dispatch &&d);

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

//! @brief xrCreateInstance wrapper.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>

template <typename Dispatch = DispatchLoaderStatic>
Result createInstance(const InstanceCreateInfo &createInfo, Instance &instance,
                      Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//! @brief xrCreateInstance wrapper - enhanced mode.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>

template <typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<Instance>::type
createInstance(const InstanceCreateInfo &createInfo, Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_NO_SMART_HANDLE

//! @brief xrCreateInstance wrapper returning a smart handle.
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>

template <typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<
    UniqueHandle<Instance, impl::RemoveRefConst<Dispatch>>>::type
createInstanceUnique(const InstanceCreateInfo &createInfo,
                     Dispatch &&d = Dispatch{});
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

//! @}

} // namespace OPENXR_HPP_NAMESPACE

// BLOCK Structure Impl definitions
namespace OPENXR_HPP_NAMESPACE {

namespace traits {

template <typename Type> class TypedStructTraits {
protected:
  TypedStructTraits(StructureType type_) : type(type_) {}

public:
  StructureType type;
  const void *next{nullptr};
};

} // namespace traits

struct CompositionLayerBaseHeader {
  StructureType type;
  const void *next;
  CompositionLayerFlags layerFlags;
  Space space;
};

struct ApiLayerProperties
    : public traits::TypedStructTraits<ApiLayerProperties> {
private:
  using Parent = traits::TypedStructTraits<ApiLayerProperties>;

public:
  // ctor
  ApiLayerProperties() : Parent(StructureType::ApiLayerProperties) {}

  operator const XrApiLayerProperties &() const {
    return *reinterpret_cast<const XrApiLayerProperties *>(this);
  }
  operator XrApiLayerProperties &() {
    return *reinterpret_cast<XrApiLayerProperties *>(this);
  }

  // member decl
  char layerName[XR_MAX_API_LAYER_NAME_SIZE];
  Version specVersion;
  uint32_t layerVersion;
  char description[XR_MAX_API_LAYER_DESCRIPTION_SIZE];
};
static_assert(sizeof(ApiLayerProperties) == sizeof(XrApiLayerProperties),
              "struct and wrapper have different size!");

struct ExtensionProperties
    : public traits::TypedStructTraits<ExtensionProperties> {
private:
  using Parent = traits::TypedStructTraits<ExtensionProperties>;

public:
  // ctor
  ExtensionProperties() : Parent(StructureType::ExtensionProperties) {}

  operator const XrExtensionProperties &() const {
    return *reinterpret_cast<const XrExtensionProperties *>(this);
  }
  operator XrExtensionProperties &() {
    return *reinterpret_cast<XrExtensionProperties *>(this);
  }

  // member decl
  char extensionName[XR_MAX_EXTENSION_NAME_SIZE];
  uint32_t extensionVersion;
};
static_assert(sizeof(ExtensionProperties) == sizeof(XrExtensionProperties),
              "struct and wrapper have different size!");

struct ApplicationInfo {
  // ctor
  ApplicationInfo(const char *applicationName_ = nullptr,
                  uint32_t applicationVersion_ = 0,
                  const char *engineName_ = nullptr,
                  uint32_t engineVersion_ = 0, const Version &apiVersion_ = {})
      :

        applicationVersion{applicationVersion_}, engineVersion{engineVersion_},
        apiVersion{apiVersion_} {
    if (nullptr != applicationName_) {
      // FIXME what is the safe way to do this?
      strncpy(applicationName, applicationName_, XR_MAX_APPLICATION_NAME_SIZE);
    }
    if (nullptr != engineName_) {
      // FIXME what is the safe way to do this?
      strncpy(engineName, engineName_, XR_MAX_ENGINE_NAME_SIZE);
    }
  }
  operator const XrApplicationInfo &() const {
    return *reinterpret_cast<const XrApplicationInfo *>(this);
  }
  operator XrApplicationInfo &() {
    return *reinterpret_cast<XrApplicationInfo *>(this);
  }

  // member decl
  char applicationName[XR_MAX_APPLICATION_NAME_SIZE];
  uint32_t applicationVersion;
  char engineName[XR_MAX_ENGINE_NAME_SIZE];
  uint32_t engineVersion;
  Version apiVersion;
};
static_assert(sizeof(ApplicationInfo) == sizeof(XrApplicationInfo),
              "struct and wrapper have different size!");

struct InstanceCreateInfo
    : public traits::TypedStructTraits<InstanceCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<InstanceCreateInfo>;

public:
  // ctor
  InstanceCreateInfo(const InstanceCreateFlags &createFlags_ = {},
                     const ApplicationInfo &applicationInfo_ = {},
                     uint32_t enabledApiLayerCount_ = 0,
                     const char *const *enabledApiLayerNames_ = nullptr,
                     uint32_t enabledExtensionCount_ = 0,
                     const char *const *enabledExtensionNames_ = nullptr)
      :

        Parent(StructureType::InstanceCreateInfo),

        createFlags{createFlags_}, applicationInfo{applicationInfo_},
        enabledApiLayerCount{enabledApiLayerCount_},
        enabledApiLayerNames{enabledApiLayerNames_},
        enabledExtensionCount{enabledExtensionCount_},
        enabledExtensionNames{enabledExtensionNames_} {}
  operator const XrInstanceCreateInfo &() const {
    return *reinterpret_cast<const XrInstanceCreateInfo *>(this);
  }
  operator XrInstanceCreateInfo &() {
    return *reinterpret_cast<XrInstanceCreateInfo *>(this);
  }

  // member decl
  InstanceCreateFlags createFlags;
  ApplicationInfo applicationInfo;
  uint32_t enabledApiLayerCount;
  const char *const *enabledApiLayerNames;
  uint32_t enabledExtensionCount;
  const char *const *enabledExtensionNames;
};
static_assert(sizeof(InstanceCreateInfo) == sizeof(XrInstanceCreateInfo),
              "struct and wrapper have different size!");

struct InstanceProperties
    : public traits::TypedStructTraits<InstanceProperties> {
private:
  using Parent = traits::TypedStructTraits<InstanceProperties>;

public:
  // ctor
  InstanceProperties() : Parent(StructureType::InstanceProperties) {}

  operator const XrInstanceProperties &() const {
    return *reinterpret_cast<const XrInstanceProperties *>(this);
  }
  operator XrInstanceProperties &() {
    return *reinterpret_cast<XrInstanceProperties *>(this);
  }

  // member decl
  Version runtimeVersion;
  char runtimeName[XR_MAX_RUNTIME_NAME_SIZE];
};
static_assert(sizeof(InstanceProperties) == sizeof(XrInstanceProperties),
              "struct and wrapper have different size!");

struct EventDataBuffer : public traits::TypedStructTraits<EventDataBuffer> {
private:
  using Parent = traits::TypedStructTraits<EventDataBuffer>;

public:
  // ctor
  EventDataBuffer() : Parent(StructureType::EventDataBuffer) {}

  operator const XrEventDataBuffer &() const {
    return *reinterpret_cast<const XrEventDataBuffer *>(this);
  }
  operator XrEventDataBuffer &() {
    return *reinterpret_cast<XrEventDataBuffer *>(this);
  }

  // member decl
  uint8_t varying[4000];
};
static_assert(sizeof(EventDataBuffer) == sizeof(XrEventDataBuffer),
              "struct and wrapper have different size!");

struct SystemGetInfo : public traits::TypedStructTraits<SystemGetInfo> {
private:
  using Parent = traits::TypedStructTraits<SystemGetInfo>;

public:
  // ctor
  SystemGetInfo(const FormFactor &formFactor_ = {})
      :

        Parent(StructureType::SystemGetInfo),

        formFactor{formFactor_} {}
  operator const XrSystemGetInfo &() const {
    return *reinterpret_cast<const XrSystemGetInfo *>(this);
  }
  operator XrSystemGetInfo &() {
    return *reinterpret_cast<XrSystemGetInfo *>(this);
  }

  // member decl
  FormFactor formFactor;
};
static_assert(sizeof(SystemGetInfo) == sizeof(XrSystemGetInfo),
              "struct and wrapper have different size!");

struct SystemGraphicsProperties {
  // ctor
  SystemGraphicsProperties(uint32_t maxSwapchainImageHeight_ = 0,
                           uint32_t maxSwapchainImageWidth_ = 0,
                           uint32_t maxLayerCount_ = 0)
      :

        maxSwapchainImageHeight{maxSwapchainImageHeight_},
        maxSwapchainImageWidth{maxSwapchainImageWidth_}, maxLayerCount{
                                                             maxLayerCount_} {}
  operator const XrSystemGraphicsProperties &() const {
    return *reinterpret_cast<const XrSystemGraphicsProperties *>(this);
  }
  operator XrSystemGraphicsProperties &() {
    return *reinterpret_cast<XrSystemGraphicsProperties *>(this);
  }

  // member decl
  uint32_t maxSwapchainImageHeight;
  uint32_t maxSwapchainImageWidth;
  uint32_t maxLayerCount;
};
static_assert(sizeof(SystemGraphicsProperties) ==
                  sizeof(XrSystemGraphicsProperties),
              "struct and wrapper have different size!");

struct SystemTrackingProperties {
  // ctor
  SystemTrackingProperties(const Bool32 &orientationTracking_ = XR_FALSE,
                           const Bool32 &positionTracking_ = XR_FALSE)
      :

        orientationTracking{orientationTracking_}, positionTracking{
                                                       positionTracking_} {}
  operator const XrSystemTrackingProperties &() const {
    return *reinterpret_cast<const XrSystemTrackingProperties *>(this);
  }
  operator XrSystemTrackingProperties &() {
    return *reinterpret_cast<XrSystemTrackingProperties *>(this);
  }

  // member decl
  Bool32 orientationTracking;
  Bool32 positionTracking;
};
static_assert(sizeof(SystemTrackingProperties) ==
                  sizeof(XrSystemTrackingProperties),
              "struct and wrapper have different size!");

struct SystemProperties : public traits::TypedStructTraits<SystemProperties> {
private:
  using Parent = traits::TypedStructTraits<SystemProperties>;

public:
  // ctor
  SystemProperties() : Parent(StructureType::SystemProperties) {}

  operator const XrSystemProperties &() const {
    return *reinterpret_cast<const XrSystemProperties *>(this);
  }
  operator XrSystemProperties &() {
    return *reinterpret_cast<XrSystemProperties *>(this);
  }

  // member decl
  SystemId systemId;
  uint32_t vendorId;
  char systemName[XR_MAX_SYSTEM_NAME_SIZE];
  SystemGraphicsProperties graphicsProperties;
  SystemTrackingProperties trackingProperties;
};
static_assert(sizeof(SystemProperties) == sizeof(XrSystemProperties),
              "struct and wrapper have different size!");

struct SessionCreateInfo : public traits::TypedStructTraits<SessionCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<SessionCreateInfo>;

public:
  // ctor
  SessionCreateInfo(const SessionCreateFlags &createFlags_ = {},
                    const SystemId &systemId_ = {})
      :

        Parent(StructureType::SessionCreateInfo),

        createFlags{createFlags_}, systemId{systemId_} {}
  operator const XrSessionCreateInfo &() const {
    return *reinterpret_cast<const XrSessionCreateInfo *>(this);
  }
  operator XrSessionCreateInfo &() {
    return *reinterpret_cast<XrSessionCreateInfo *>(this);
  }

  // member decl
  SessionCreateFlags createFlags;
  SystemId systemId;
};
static_assert(sizeof(SessionCreateInfo) == sizeof(XrSessionCreateInfo),
              "struct and wrapper have different size!");

struct Vector3f {
  // ctor
  Vector3f(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f)
      :

        x{x_}, y{y_}, z{z_} {}
  operator const XrVector3f &() const {
    return *reinterpret_cast<const XrVector3f *>(this);
  }
  operator XrVector3f &() { return *reinterpret_cast<XrVector3f *>(this); }

  // member decl
  float x;
  float y;
  float z;
};
static_assert(sizeof(Vector3f) == sizeof(XrVector3f),
              "struct and wrapper have different size!");

struct SpaceVelocity : public traits::TypedStructTraits<SpaceVelocity> {
private:
  using Parent = traits::TypedStructTraits<SpaceVelocity>;

public:
  // ctor
  SpaceVelocity(const SpaceVelocityFlags &velocityFlags_ = {},
                const Vector3f &linearVelocity_ = {},
                const Vector3f &angularVelocity_ = {})
      :

        Parent(StructureType::SpaceVelocity),

        velocityFlags{velocityFlags_}, linearVelocity{linearVelocity_},
        angularVelocity{angularVelocity_} {}
  operator const XrSpaceVelocity &() const {
    return *reinterpret_cast<const XrSpaceVelocity *>(this);
  }
  operator XrSpaceVelocity &() {
    return *reinterpret_cast<XrSpaceVelocity *>(this);
  }

  // member decl
  SpaceVelocityFlags velocityFlags;
  Vector3f linearVelocity;
  Vector3f angularVelocity;
};
static_assert(sizeof(SpaceVelocity) == sizeof(XrSpaceVelocity),
              "struct and wrapper have different size!");

struct Quaternionf {
  // ctor
  Quaternionf(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f,
              float w_ = 1.0f)
      :

        x{x_}, y{y_}, z{z_}, w{w_} {}
  operator const XrQuaternionf &() const {
    return *reinterpret_cast<const XrQuaternionf *>(this);
  }
  operator XrQuaternionf &() {
    return *reinterpret_cast<XrQuaternionf *>(this);
  }

  // member decl
  float x;
  float y;
  float z;
  float w;
};
static_assert(sizeof(Quaternionf) == sizeof(XrQuaternionf),
              "struct and wrapper have different size!");

struct Posef {
  // ctor
  Posef(const Quaternionf &orientation_ = {}, const Vector3f &position_ = {})
      :

        orientation{orientation_}, position{position_} {}
  operator const XrPosef &() const {
    return *reinterpret_cast<const XrPosef *>(this);
  }
  operator XrPosef &() { return *reinterpret_cast<XrPosef *>(this); }

  // member decl
  Quaternionf orientation;
  Vector3f position;
};
static_assert(sizeof(Posef) == sizeof(XrPosef),
              "struct and wrapper have different size!");

struct ReferenceSpaceCreateInfo
    : public traits::TypedStructTraits<ReferenceSpaceCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<ReferenceSpaceCreateInfo>;

public:
  // ctor
  ReferenceSpaceCreateInfo(const ReferenceSpaceType &referenceSpaceType_ = {},
                           const Posef &poseInReferenceSpace_ = {})
      :

        Parent(StructureType::ReferenceSpaceCreateInfo),

        referenceSpaceType{referenceSpaceType_}, poseInReferenceSpace{
                                                     poseInReferenceSpace_} {}
  operator const XrReferenceSpaceCreateInfo &() const {
    return *reinterpret_cast<const XrReferenceSpaceCreateInfo *>(this);
  }
  operator XrReferenceSpaceCreateInfo &() {
    return *reinterpret_cast<XrReferenceSpaceCreateInfo *>(this);
  }

  // member decl
  ReferenceSpaceType referenceSpaceType;
  Posef poseInReferenceSpace;
};
static_assert(sizeof(ReferenceSpaceCreateInfo) ==
                  sizeof(XrReferenceSpaceCreateInfo),
              "struct and wrapper have different size!");

struct Extent2Df {
  // ctor
  Extent2Df(float width_ = 0.0f, float height_ = 0.0f)
      :

        width{width_}, height{height_} {}
  operator const XrExtent2Df &() const {
    return *reinterpret_cast<const XrExtent2Df *>(this);
  }
  operator XrExtent2Df &() { return *reinterpret_cast<XrExtent2Df *>(this); }

  // member decl
  float width;
  float height;
};
static_assert(sizeof(Extent2Df) == sizeof(XrExtent2Df),
              "struct and wrapper have different size!");

struct ActionSpaceCreateInfo
    : public traits::TypedStructTraits<ActionSpaceCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<ActionSpaceCreateInfo>;

public:
  // ctor
  ActionSpaceCreateInfo(const Action &action_ = {},
                        const Path &subactionPath_ = {},
                        const Posef &poseInActionSpace_ = {})
      :

        Parent(StructureType::ActionSpaceCreateInfo),

        action{action_}, subactionPath{subactionPath_},
        poseInActionSpace{poseInActionSpace_} {}
  operator const XrActionSpaceCreateInfo &() const {
    return *reinterpret_cast<const XrActionSpaceCreateInfo *>(this);
  }
  operator XrActionSpaceCreateInfo &() {
    return *reinterpret_cast<XrActionSpaceCreateInfo *>(this);
  }

  // member decl
  Action action;
  Path subactionPath;
  Posef poseInActionSpace;
};
static_assert(sizeof(ActionSpaceCreateInfo) == sizeof(XrActionSpaceCreateInfo),
              "struct and wrapper have different size!");

struct SpaceLocation : public traits::TypedStructTraits<SpaceLocation> {
private:
  using Parent = traits::TypedStructTraits<SpaceLocation>;

public:
  // ctor
  SpaceLocation(const SpaceLocationFlags &locationFlags_ = {},
                const Posef &pose_ = {})
      :

        Parent(StructureType::SpaceLocation),

        locationFlags{locationFlags_}, pose{pose_} {}
  operator const XrSpaceLocation &() const {
    return *reinterpret_cast<const XrSpaceLocation *>(this);
  }
  operator XrSpaceLocation &() {
    return *reinterpret_cast<XrSpaceLocation *>(this);
  }

  // member decl
  SpaceLocationFlags locationFlags;
  Posef pose;
};
static_assert(sizeof(SpaceLocation) == sizeof(XrSpaceLocation),
              "struct and wrapper have different size!");

struct ViewConfigurationProperties
    : public traits::TypedStructTraits<ViewConfigurationProperties> {
private:
  using Parent = traits::TypedStructTraits<ViewConfigurationProperties>;

public:
  // ctor
  ViewConfigurationProperties(
      const ViewConfigurationType &viewConfigurationType_ = {},
      const Bool32 &fovMutable_ = XR_FALSE)
      :

        Parent(StructureType::ViewConfigurationProperties),

        viewConfigurationType{viewConfigurationType_}, fovMutable{fovMutable_} {
  }
  operator const XrViewConfigurationProperties &() const {
    return *reinterpret_cast<const XrViewConfigurationProperties *>(this);
  }
  operator XrViewConfigurationProperties &() {
    return *reinterpret_cast<XrViewConfigurationProperties *>(this);
  }

  // member decl
  ViewConfigurationType viewConfigurationType;
  Bool32 fovMutable;
};
static_assert(sizeof(ViewConfigurationProperties) ==
                  sizeof(XrViewConfigurationProperties),
              "struct and wrapper have different size!");

struct ViewConfigurationView
    : public traits::TypedStructTraits<ViewConfigurationView> {
private:
  using Parent = traits::TypedStructTraits<ViewConfigurationView>;

public:
  // ctor
  ViewConfigurationView(uint32_t recommendedImageRectWidth_ = 0,
                        uint32_t maxImageRectWidth_ = 0,
                        uint32_t recommendedImageRectHeight_ = 0,
                        uint32_t maxImageRectHeight_ = 0,
                        uint32_t recommendedSwapchainSampleCount_ = 0,
                        uint32_t maxSwapchainSampleCount_ = 0)
      :

        Parent(StructureType::ViewConfigurationView),

        recommendedImageRectWidth{recommendedImageRectWidth_},
        maxImageRectWidth{maxImageRectWidth_},
        recommendedImageRectHeight{recommendedImageRectHeight_},
        maxImageRectHeight{maxImageRectHeight_},
        recommendedSwapchainSampleCount{recommendedSwapchainSampleCount_},
        maxSwapchainSampleCount{maxSwapchainSampleCount_} {}
  operator const XrViewConfigurationView &() const {
    return *reinterpret_cast<const XrViewConfigurationView *>(this);
  }
  operator XrViewConfigurationView &() {
    return *reinterpret_cast<XrViewConfigurationView *>(this);
  }

  // member decl
  uint32_t recommendedImageRectWidth;
  uint32_t maxImageRectWidth;
  uint32_t recommendedImageRectHeight;
  uint32_t maxImageRectHeight;
  uint32_t recommendedSwapchainSampleCount;
  uint32_t maxSwapchainSampleCount;
};
static_assert(sizeof(ViewConfigurationView) == sizeof(XrViewConfigurationView),
              "struct and wrapper have different size!");

struct SwapchainCreateInfo
    : public traits::TypedStructTraits<SwapchainCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<SwapchainCreateInfo>;

public:
  // ctor
  SwapchainCreateInfo(const SwapchainCreateFlags &createFlags_ = {},
                      const SwapchainUsageFlags &usageFlags_ = {},
                      int64_t format_ = 0, uint32_t sampleCount_ = 0,
                      uint32_t width_ = 0, uint32_t height_ = 0,
                      uint32_t faceCount_ = 0, uint32_t arraySize_ = 0,
                      uint32_t mipCount_ = 0)
      :

        Parent(StructureType::SwapchainCreateInfo),

        createFlags{createFlags_}, usageFlags{usageFlags_}, format{format_},
        sampleCount{sampleCount_}, width{width_}, height{height_},
        faceCount{faceCount_}, arraySize{arraySize_}, mipCount{mipCount_} {}
  operator const XrSwapchainCreateInfo &() const {
    return *reinterpret_cast<const XrSwapchainCreateInfo *>(this);
  }
  operator XrSwapchainCreateInfo &() {
    return *reinterpret_cast<XrSwapchainCreateInfo *>(this);
  }

  // member decl
  SwapchainCreateFlags createFlags;
  SwapchainUsageFlags usageFlags;
  int64_t format;
  uint32_t sampleCount;
  uint32_t width;
  uint32_t height;
  uint32_t faceCount;
  uint32_t arraySize;
  uint32_t mipCount;
};
static_assert(sizeof(SwapchainCreateInfo) == sizeof(XrSwapchainCreateInfo),
              "struct and wrapper have different size!");

struct SwapchainImageAcquireInfo
    : public traits::TypedStructTraits<SwapchainImageAcquireInfo> {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageAcquireInfo>;

public:
  // ctor
  SwapchainImageAcquireInfo()
      :

        Parent(StructureType::SwapchainImageAcquireInfo)

  {}
  operator const XrSwapchainImageAcquireInfo &() const {
    return *reinterpret_cast<const XrSwapchainImageAcquireInfo *>(this);
  }
  operator XrSwapchainImageAcquireInfo &() {
    return *reinterpret_cast<XrSwapchainImageAcquireInfo *>(this);
  }

  // member decl
};
static_assert(sizeof(SwapchainImageAcquireInfo) ==
                  sizeof(XrSwapchainImageAcquireInfo),
              "struct and wrapper have different size!");

struct SwapchainImageWaitInfo
    : public traits::TypedStructTraits<SwapchainImageWaitInfo> {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageWaitInfo>;

public:
  // ctor
  SwapchainImageWaitInfo(const Duration &timeout_ = {})
      :

        Parent(StructureType::SwapchainImageWaitInfo),

        timeout{timeout_} {}
  operator const XrSwapchainImageWaitInfo &() const {
    return *reinterpret_cast<const XrSwapchainImageWaitInfo *>(this);
  }
  operator XrSwapchainImageWaitInfo &() {
    return *reinterpret_cast<XrSwapchainImageWaitInfo *>(this);
  }

  // member decl
  Duration timeout;
};
static_assert(sizeof(SwapchainImageWaitInfo) ==
                  sizeof(XrSwapchainImageWaitInfo),
              "struct and wrapper have different size!");

struct SwapchainImageReleaseInfo
    : public traits::TypedStructTraits<SwapchainImageReleaseInfo> {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageReleaseInfo>;

public:
  // ctor
  SwapchainImageReleaseInfo()
      :

        Parent(StructureType::SwapchainImageReleaseInfo)

  {}
  operator const XrSwapchainImageReleaseInfo &() const {
    return *reinterpret_cast<const XrSwapchainImageReleaseInfo *>(this);
  }
  operator XrSwapchainImageReleaseInfo &() {
    return *reinterpret_cast<XrSwapchainImageReleaseInfo *>(this);
  }

  // member decl
};
static_assert(sizeof(SwapchainImageReleaseInfo) ==
                  sizeof(XrSwapchainImageReleaseInfo),
              "struct and wrapper have different size!");

struct SessionBeginInfo : public traits::TypedStructTraits<SessionBeginInfo> {
private:
  using Parent = traits::TypedStructTraits<SessionBeginInfo>;

public:
  // ctor
  SessionBeginInfo(
      const ViewConfigurationType &primaryViewConfigurationType_ = {})
      :

        Parent(StructureType::SessionBeginInfo),

        primaryViewConfigurationType{primaryViewConfigurationType_} {}
  operator const XrSessionBeginInfo &() const {
    return *reinterpret_cast<const XrSessionBeginInfo *>(this);
  }
  operator XrSessionBeginInfo &() {
    return *reinterpret_cast<XrSessionBeginInfo *>(this);
  }

  // member decl
  ViewConfigurationType primaryViewConfigurationType;
};
static_assert(sizeof(SessionBeginInfo) == sizeof(XrSessionBeginInfo),
              "struct and wrapper have different size!");

struct FrameWaitInfo : public traits::TypedStructTraits<FrameWaitInfo> {
private:
  using Parent = traits::TypedStructTraits<FrameWaitInfo>;

public:
  // ctor
  FrameWaitInfo()
      :

        Parent(StructureType::FrameWaitInfo)

  {}
  operator const XrFrameWaitInfo &() const {
    return *reinterpret_cast<const XrFrameWaitInfo *>(this);
  }
  operator XrFrameWaitInfo &() {
    return *reinterpret_cast<XrFrameWaitInfo *>(this);
  }

  // member decl
};
static_assert(sizeof(FrameWaitInfo) == sizeof(XrFrameWaitInfo),
              "struct and wrapper have different size!");

struct FrameState : public traits::TypedStructTraits<FrameState> {
private:
  using Parent = traits::TypedStructTraits<FrameState>;

public:
  // ctor
  FrameState(const Time &predictedDisplayTime_ = {},
             const Duration &predictedDisplayPeriod_ = {},
             const Bool32 &shouldRender_ = XR_FALSE)
      :

        Parent(StructureType::FrameState),

        predictedDisplayTime{predictedDisplayTime_},
        predictedDisplayPeriod{predictedDisplayPeriod_}, shouldRender{
                                                             shouldRender_} {}
  operator const XrFrameState &() const {
    return *reinterpret_cast<const XrFrameState *>(this);
  }
  operator XrFrameState &() { return *reinterpret_cast<XrFrameState *>(this); }

  // member decl
  Time predictedDisplayTime;
  Duration predictedDisplayPeriod;
  Bool32 shouldRender;
};
static_assert(sizeof(FrameState) == sizeof(XrFrameState),
              "struct and wrapper have different size!");

struct FrameBeginInfo : public traits::TypedStructTraits<FrameBeginInfo> {
private:
  using Parent = traits::TypedStructTraits<FrameBeginInfo>;

public:
  // ctor
  FrameBeginInfo()
      :

        Parent(StructureType::FrameBeginInfo)

  {}
  operator const XrFrameBeginInfo &() const {
    return *reinterpret_cast<const XrFrameBeginInfo *>(this);
  }
  operator XrFrameBeginInfo &() {
    return *reinterpret_cast<XrFrameBeginInfo *>(this);
  }

  // member decl
};
static_assert(sizeof(FrameBeginInfo) == sizeof(XrFrameBeginInfo),
              "struct and wrapper have different size!");

struct FrameEndInfo : public traits::TypedStructTraits<FrameEndInfo> {
private:
  using Parent = traits::TypedStructTraits<FrameEndInfo>;

public:
  // ctor
  FrameEndInfo(const Time &displayTime_ = {},
               const EnvironmentBlendMode &environmentBlendMode_ = {},
               uint32_t layerCount_ = 0,
               const CompositionLayerBaseHeader *const *layers_ = nullptr)
      :

        Parent(StructureType::FrameEndInfo),

        displayTime{displayTime_}, environmentBlendMode{environmentBlendMode_},
        layerCount{layerCount_}, layers{layers_} {}
  operator const XrFrameEndInfo &() const {
    return *reinterpret_cast<const XrFrameEndInfo *>(this);
  }
  operator XrFrameEndInfo &() {
    return *reinterpret_cast<XrFrameEndInfo *>(this);
  }

  // member decl
  Time displayTime;
  EnvironmentBlendMode environmentBlendMode;
  uint32_t layerCount;
  const CompositionLayerBaseHeader *const *layers;
};
static_assert(sizeof(FrameEndInfo) == sizeof(XrFrameEndInfo),
              "struct and wrapper have different size!");

struct ViewLocateInfo : public traits::TypedStructTraits<ViewLocateInfo> {
private:
  using Parent = traits::TypedStructTraits<ViewLocateInfo>;

public:
  // ctor
  ViewLocateInfo(const ViewConfigurationType &viewConfigurationType_ = {},
                 const Time &displayTime_ = {}, const Space &space_ = {})
      :

        Parent(StructureType::ViewLocateInfo),

        viewConfigurationType{viewConfigurationType_},
        displayTime{displayTime_}, space{space_} {}
  operator const XrViewLocateInfo &() const {
    return *reinterpret_cast<const XrViewLocateInfo *>(this);
  }
  operator XrViewLocateInfo &() {
    return *reinterpret_cast<XrViewLocateInfo *>(this);
  }

  // member decl
  ViewConfigurationType viewConfigurationType;
  Time displayTime;
  Space space;
};
static_assert(sizeof(ViewLocateInfo) == sizeof(XrViewLocateInfo),
              "struct and wrapper have different size!");

struct ViewState : public traits::TypedStructTraits<ViewState> {
private:
  using Parent = traits::TypedStructTraits<ViewState>;

public:
  // ctor
  ViewState(const ViewStateFlags &viewStateFlags_ = {})
      :

        Parent(StructureType::ViewState),

        viewStateFlags{viewStateFlags_} {}
  operator const XrViewState &() const {
    return *reinterpret_cast<const XrViewState *>(this);
  }
  operator XrViewState &() { return *reinterpret_cast<XrViewState *>(this); }

  // member decl
  ViewStateFlags viewStateFlags;
};
static_assert(sizeof(ViewState) == sizeof(XrViewState),
              "struct and wrapper have different size!");

struct Fovf {
  // ctor
  Fovf(float angleLeft_ = 0.0f, float angleRight_ = 0.0f, float angleUp_ = 0.0f,
       float angleDown_ = 0.0f)
      :

        angleLeft{angleLeft_},
        angleRight{angleRight_}, angleUp{angleUp_}, angleDown{angleDown_} {}
  operator const XrFovf &() const {
    return *reinterpret_cast<const XrFovf *>(this);
  }
  operator XrFovf &() { return *reinterpret_cast<XrFovf *>(this); }

  // member decl
  float angleLeft;
  float angleRight;
  float angleUp;
  float angleDown;
};
static_assert(sizeof(Fovf) == sizeof(XrFovf),
              "struct and wrapper have different size!");

struct View : public traits::TypedStructTraits<View> {
private:
  using Parent = traits::TypedStructTraits<View>;

public:
  // ctor
  View(const Posef &pose_ = {}, const Fovf &fov_ = {})
      :

        Parent(StructureType::View),

        pose{pose_}, fov{fov_} {}
  operator const XrView &() const {
    return *reinterpret_cast<const XrView *>(this);
  }
  operator XrView &() { return *reinterpret_cast<XrView *>(this); }

  // member decl
  Posef pose;
  Fovf fov;
};
static_assert(sizeof(View) == sizeof(XrView),
              "struct and wrapper have different size!");

struct ActionSetCreateInfo
    : public traits::TypedStructTraits<ActionSetCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<ActionSetCreateInfo>;

public:
  // ctor
  ActionSetCreateInfo(const char *actionSetName_ = nullptr,
                      const char *localizedActionSetName_ = nullptr,
                      uint32_t priority_ = 0)
      :

        Parent(StructureType::ActionSetCreateInfo),

        priority{priority_} {
    if (nullptr != actionSetName_) {
      // FIXME what is the safe way to do this?
      strncpy(actionSetName, actionSetName_, XR_MAX_ACTION_SET_NAME_SIZE);
    }
    if (nullptr != localizedActionSetName_) {
      // FIXME what is the safe way to do this?
      strncpy(localizedActionSetName, localizedActionSetName_,
              XR_MAX_LOCALIZED_ACTION_SET_NAME_SIZE);
    }
  }
  operator const XrActionSetCreateInfo &() const {
    return *reinterpret_cast<const XrActionSetCreateInfo *>(this);
  }
  operator XrActionSetCreateInfo &() {
    return *reinterpret_cast<XrActionSetCreateInfo *>(this);
  }

  // member decl
  char actionSetName[XR_MAX_ACTION_SET_NAME_SIZE];
  char localizedActionSetName[XR_MAX_LOCALIZED_ACTION_SET_NAME_SIZE];
  uint32_t priority;
};
static_assert(sizeof(ActionSetCreateInfo) == sizeof(XrActionSetCreateInfo),
              "struct and wrapper have different size!");

struct ActionCreateInfo : public traits::TypedStructTraits<ActionCreateInfo> {
private:
  using Parent = traits::TypedStructTraits<ActionCreateInfo>;

public:
  // ctor
  ActionCreateInfo(const char *actionName_ = nullptr,
                   const ActionType &actionType_ = {},
                   uint32_t countSubactionPaths_ = 0,
                   const Path *subactionPaths_ = nullptr,
                   const char *localizedActionName_ = nullptr)
      :

        Parent(StructureType::ActionCreateInfo),

        actionType{actionType_}, countSubactionPaths{countSubactionPaths_},
        subactionPaths{subactionPaths_} {
    if (nullptr != actionName_) {
      // FIXME what is the safe way to do this?
      strncpy(actionName, actionName_, XR_MAX_ACTION_NAME_SIZE);
    }
    if (nullptr != localizedActionName_) {
      // FIXME what is the safe way to do this?
      strncpy(localizedActionName, localizedActionName_,
              XR_MAX_LOCALIZED_ACTION_NAME_SIZE);
    }
  }
  operator const XrActionCreateInfo &() const {
    return *reinterpret_cast<const XrActionCreateInfo *>(this);
  }
  operator XrActionCreateInfo &() {
    return *reinterpret_cast<XrActionCreateInfo *>(this);
  }

  // member decl
  char actionName[XR_MAX_ACTION_NAME_SIZE];
  ActionType actionType;
  uint32_t countSubactionPaths;
  const Path *subactionPaths;
  char localizedActionName[XR_MAX_LOCALIZED_ACTION_NAME_SIZE];
};
static_assert(sizeof(ActionCreateInfo) == sizeof(XrActionCreateInfo),
              "struct and wrapper have different size!");

struct ActionSuggestedBinding {
  // ctor
  ActionSuggestedBinding(const Action &action_ = {}, const Path &binding_ = {})
      :

        action{action_}, binding{binding_} {}
  operator const XrActionSuggestedBinding &() const {
    return *reinterpret_cast<const XrActionSuggestedBinding *>(this);
  }
  operator XrActionSuggestedBinding &() {
    return *reinterpret_cast<XrActionSuggestedBinding *>(this);
  }

  // member decl
  Action action;
  Path binding;
};
static_assert(sizeof(ActionSuggestedBinding) ==
                  sizeof(XrActionSuggestedBinding),
              "struct and wrapper have different size!");

struct InteractionProfileSuggestedBinding
    : public traits::TypedStructTraits<InteractionProfileSuggestedBinding> {
private:
  using Parent = traits::TypedStructTraits<InteractionProfileSuggestedBinding>;

public:
  // ctor
  InteractionProfileSuggestedBinding(
      const Path &interactionProfile_ = {},
      uint32_t countSuggestedBindings_ = 0,
      const ActionSuggestedBinding *suggestedBindings_ = nullptr)
      :

        Parent(StructureType::InteractionProfileSuggestedBinding),

        interactionProfile{interactionProfile_},
        countSuggestedBindings{countSuggestedBindings_},
        suggestedBindings{suggestedBindings_} {}
  operator const XrInteractionProfileSuggestedBinding &() const {
    return *reinterpret_cast<const XrInteractionProfileSuggestedBinding *>(
        this);
  }
  operator XrInteractionProfileSuggestedBinding &() {
    return *reinterpret_cast<XrInteractionProfileSuggestedBinding *>(this);
  }

  // member decl
  Path interactionProfile;
  uint32_t countSuggestedBindings;
  const ActionSuggestedBinding *suggestedBindings;
};
static_assert(sizeof(InteractionProfileSuggestedBinding) ==
                  sizeof(XrInteractionProfileSuggestedBinding),
              "struct and wrapper have different size!");

struct SessionActionSetsAttachInfo
    : public traits::TypedStructTraits<SessionActionSetsAttachInfo> {
private:
  using Parent = traits::TypedStructTraits<SessionActionSetsAttachInfo>;

public:
  // ctor
  SessionActionSetsAttachInfo(uint32_t countActionSets_ = 0,
                              const ActionSet *actionSets_ = nullptr)
      :

        Parent(StructureType::SessionActionSetsAttachInfo),

        countActionSets{countActionSets_}, actionSets{actionSets_} {}
  operator const XrSessionActionSetsAttachInfo &() const {
    return *reinterpret_cast<const XrSessionActionSetsAttachInfo *>(this);
  }
  operator XrSessionActionSetsAttachInfo &() {
    return *reinterpret_cast<XrSessionActionSetsAttachInfo *>(this);
  }

  // member decl
  uint32_t countActionSets;
  const ActionSet *actionSets;
};
static_assert(sizeof(SessionActionSetsAttachInfo) ==
                  sizeof(XrSessionActionSetsAttachInfo),
              "struct and wrapper have different size!");

struct InteractionProfileState
    : public traits::TypedStructTraits<InteractionProfileState> {
private:
  using Parent = traits::TypedStructTraits<InteractionProfileState>;

public:
  // ctor
  InteractionProfileState(const Path &interactionProfile_ = {})
      :

        Parent(StructureType::InteractionProfileState),

        interactionProfile{interactionProfile_} {}
  operator const XrInteractionProfileState &() const {
    return *reinterpret_cast<const XrInteractionProfileState *>(this);
  }
  operator XrInteractionProfileState &() {
    return *reinterpret_cast<XrInteractionProfileState *>(this);
  }

  // member decl
  Path interactionProfile;
};
static_assert(sizeof(InteractionProfileState) ==
                  sizeof(XrInteractionProfileState),
              "struct and wrapper have different size!");

struct ActionStateGetInfo
    : public traits::TypedStructTraits<ActionStateGetInfo> {
private:
  using Parent = traits::TypedStructTraits<ActionStateGetInfo>;

public:
  // ctor
  ActionStateGetInfo(const Action &action_ = {},
                     const Path &subactionPath_ = {})
      :

        Parent(StructureType::ActionStateGetInfo),

        action{action_}, subactionPath{subactionPath_} {}
  operator const XrActionStateGetInfo &() const {
    return *reinterpret_cast<const XrActionStateGetInfo *>(this);
  }
  operator XrActionStateGetInfo &() {
    return *reinterpret_cast<XrActionStateGetInfo *>(this);
  }

  // member decl
  Action action;
  Path subactionPath;
};
static_assert(sizeof(ActionStateGetInfo) == sizeof(XrActionStateGetInfo),
              "struct and wrapper have different size!");

struct ActionStateBoolean
    : public traits::TypedStructTraits<ActionStateBoolean> {
private:
  using Parent = traits::TypedStructTraits<ActionStateBoolean>;

public:
  // ctor
  ActionStateBoolean(const Bool32 &currentState_ = XR_FALSE,
                     const Bool32 &changedSinceLastSync_ = XR_FALSE,
                     const Time &lastChangeTime_ = {},
                     const Bool32 &isActive_ = XR_FALSE)
      :

        Parent(StructureType::ActionStateBoolean),

        currentState{currentState_},
        changedSinceLastSync{changedSinceLastSync_},
        lastChangeTime{lastChangeTime_}, isActive{isActive_} {}
  operator const XrActionStateBoolean &() const {
    return *reinterpret_cast<const XrActionStateBoolean *>(this);
  }
  operator XrActionStateBoolean &() {
    return *reinterpret_cast<XrActionStateBoolean *>(this);
  }

  // member decl
  Bool32 currentState;
  Bool32 changedSinceLastSync;
  Time lastChangeTime;
  Bool32 isActive;
};
static_assert(sizeof(ActionStateBoolean) == sizeof(XrActionStateBoolean),
              "struct and wrapper have different size!");

struct ActionStateFloat : public traits::TypedStructTraits<ActionStateFloat> {
private:
  using Parent = traits::TypedStructTraits<ActionStateFloat>;

public:
  // ctor
  ActionStateFloat(float currentState_ = 0.0f,
                   const Bool32 &changedSinceLastSync_ = XR_FALSE,
                   const Time &lastChangeTime_ = {},
                   const Bool32 &isActive_ = XR_FALSE)
      :

        Parent(StructureType::ActionStateFloat),

        currentState{currentState_},
        changedSinceLastSync{changedSinceLastSync_},
        lastChangeTime{lastChangeTime_}, isActive{isActive_} {}
  operator const XrActionStateFloat &() const {
    return *reinterpret_cast<const XrActionStateFloat *>(this);
  }
  operator XrActionStateFloat &() {
    return *reinterpret_cast<XrActionStateFloat *>(this);
  }

  // member decl
  float currentState;
  Bool32 changedSinceLastSync;
  Time lastChangeTime;
  Bool32 isActive;
};
static_assert(sizeof(ActionStateFloat) == sizeof(XrActionStateFloat),
              "struct and wrapper have different size!");

struct Vector2f {
  // ctor
  Vector2f(float x_ = 0.0f, float y_ = 0.0f)
      :

        x{x_}, y{y_} {}
  operator const XrVector2f &() const {
    return *reinterpret_cast<const XrVector2f *>(this);
  }
  operator XrVector2f &() { return *reinterpret_cast<XrVector2f *>(this); }

  // member decl
  float x;
  float y;
};
static_assert(sizeof(Vector2f) == sizeof(XrVector2f),
              "struct and wrapper have different size!");

struct ActionStateVector2f
    : public traits::TypedStructTraits<ActionStateVector2f> {
private:
  using Parent = traits::TypedStructTraits<ActionStateVector2f>;

public:
  // ctor
  ActionStateVector2f(const Vector2f &currentState_ = {},
                      const Bool32 &changedSinceLastSync_ = XR_FALSE,
                      const Time &lastChangeTime_ = {},
                      const Bool32 &isActive_ = XR_FALSE)
      :

        Parent(StructureType::ActionStateVector2F),

        currentState{currentState_},
        changedSinceLastSync{changedSinceLastSync_},
        lastChangeTime{lastChangeTime_}, isActive{isActive_} {}
  operator const XrActionStateVector2f &() const {
    return *reinterpret_cast<const XrActionStateVector2f *>(this);
  }
  operator XrActionStateVector2f &() {
    return *reinterpret_cast<XrActionStateVector2f *>(this);
  }

  // member decl
  Vector2f currentState;
  Bool32 changedSinceLastSync;
  Time lastChangeTime;
  Bool32 isActive;
};
static_assert(sizeof(ActionStateVector2f) == sizeof(XrActionStateVector2f),
              "struct and wrapper have different size!");

struct ActionStatePose : public traits::TypedStructTraits<ActionStatePose> {
private:
  using Parent = traits::TypedStructTraits<ActionStatePose>;

public:
  // ctor
  ActionStatePose(const Bool32 &isActive_ = XR_FALSE)
      :

        Parent(StructureType::ActionStatePose),

        isActive{isActive_} {}
  operator const XrActionStatePose &() const {
    return *reinterpret_cast<const XrActionStatePose *>(this);
  }
  operator XrActionStatePose &() {
    return *reinterpret_cast<XrActionStatePose *>(this);
  }

  // member decl
  Bool32 isActive;
};
static_assert(sizeof(ActionStatePose) == sizeof(XrActionStatePose),
              "struct and wrapper have different size!");

struct ActiveActionSet {
  // ctor
  ActiveActionSet(const ActionSet &actionSet_ = {},
                  const Path &subactionPath_ = {})
      :

        actionSet{actionSet_}, subactionPath{subactionPath_} {}
  operator const XrActiveActionSet &() const {
    return *reinterpret_cast<const XrActiveActionSet *>(this);
  }
  operator XrActiveActionSet &() {
    return *reinterpret_cast<XrActiveActionSet *>(this);
  }

  // member decl
  ActionSet actionSet;
  Path subactionPath;
};
static_assert(sizeof(ActiveActionSet) == sizeof(XrActiveActionSet),
              "struct and wrapper have different size!");

struct ActionsSyncInfo : public traits::TypedStructTraits<ActionsSyncInfo> {
private:
  using Parent = traits::TypedStructTraits<ActionsSyncInfo>;

public:
  // ctor
  ActionsSyncInfo(uint32_t countActiveActionSets_ = 0,
                  const ActiveActionSet *activeActionSets_ = nullptr)
      :

        Parent(StructureType::ActionsSyncInfo),

        countActiveActionSets{countActiveActionSets_}, activeActionSets{
                                                           activeActionSets_} {}
  operator const XrActionsSyncInfo &() const {
    return *reinterpret_cast<const XrActionsSyncInfo *>(this);
  }
  operator XrActionsSyncInfo &() {
    return *reinterpret_cast<XrActionsSyncInfo *>(this);
  }

  // member decl
  uint32_t countActiveActionSets;
  const ActiveActionSet *activeActionSets;
};
static_assert(sizeof(ActionsSyncInfo) == sizeof(XrActionsSyncInfo),
              "struct and wrapper have different size!");

struct BoundSourcesForActionEnumerateInfo
    : public traits::TypedStructTraits<BoundSourcesForActionEnumerateInfo> {
private:
  using Parent = traits::TypedStructTraits<BoundSourcesForActionEnumerateInfo>;

public:
  // ctor
  BoundSourcesForActionEnumerateInfo(const Action &action_ = {})
      :

        Parent(StructureType::BoundSourcesForActionEnumerateInfo),

        action{action_} {}
  operator const XrBoundSourcesForActionEnumerateInfo &() const {
    return *reinterpret_cast<const XrBoundSourcesForActionEnumerateInfo *>(
        this);
  }
  operator XrBoundSourcesForActionEnumerateInfo &() {
    return *reinterpret_cast<XrBoundSourcesForActionEnumerateInfo *>(this);
  }

  // member decl
  Action action;
};
static_assert(sizeof(BoundSourcesForActionEnumerateInfo) ==
                  sizeof(XrBoundSourcesForActionEnumerateInfo),
              "struct and wrapper have different size!");

struct InputSourceLocalizedNameGetInfo
    : public traits::TypedStructTraits<InputSourceLocalizedNameGetInfo> {
private:
  using Parent = traits::TypedStructTraits<InputSourceLocalizedNameGetInfo>;

public:
  // ctor
  InputSourceLocalizedNameGetInfo(
      const Path &sourcePath_ = {},
      const InputSourceLocalizedNameFlags &whichComponents_ = {})
      :

        Parent(StructureType::InputSourceLocalizedNameGetInfo),

        sourcePath{sourcePath_}, whichComponents{whichComponents_} {}
  operator const XrInputSourceLocalizedNameGetInfo &() const {
    return *reinterpret_cast<const XrInputSourceLocalizedNameGetInfo *>(this);
  }
  operator XrInputSourceLocalizedNameGetInfo &() {
    return *reinterpret_cast<XrInputSourceLocalizedNameGetInfo *>(this);
  }

  // member decl
  Path sourcePath;
  InputSourceLocalizedNameFlags whichComponents;
};
static_assert(sizeof(InputSourceLocalizedNameGetInfo) ==
                  sizeof(XrInputSourceLocalizedNameGetInfo),
              "struct and wrapper have different size!");

struct HapticActionInfo : public traits::TypedStructTraits<HapticActionInfo> {
private:
  using Parent = traits::TypedStructTraits<HapticActionInfo>;

public:
  // ctor
  HapticActionInfo(const Action &action_ = {}, const Path &subactionPath_ = {})
      :

        Parent(StructureType::HapticActionInfo),

        action{action_}, subactionPath{subactionPath_} {}
  operator const XrHapticActionInfo &() const {
    return *reinterpret_cast<const XrHapticActionInfo *>(this);
  }
  operator XrHapticActionInfo &() {
    return *reinterpret_cast<XrHapticActionInfo *>(this);
  }

  // member decl
  Action action;
  Path subactionPath;
};
static_assert(sizeof(HapticActionInfo) == sizeof(XrHapticActionInfo),
              "struct and wrapper have different size!");

struct Offset2Di {
  // ctor
  Offset2Di(int32_t x_ = 0, int32_t y_ = 0)
      :

        x{x_}, y{y_} {}
  operator const XrOffset2Di &() const {
    return *reinterpret_cast<const XrOffset2Di *>(this);
  }
  operator XrOffset2Di &() { return *reinterpret_cast<XrOffset2Di *>(this); }

  // member decl
  int32_t x;
  int32_t y;
};
static_assert(sizeof(Offset2Di) == sizeof(XrOffset2Di),
              "struct and wrapper have different size!");

struct Extent2Di {
  // ctor
  Extent2Di(int32_t width_ = 0, int32_t height_ = 0)
      :

        width{width_}, height{height_} {}
  operator const XrExtent2Di &() const {
    return *reinterpret_cast<const XrExtent2Di *>(this);
  }
  operator XrExtent2Di &() { return *reinterpret_cast<XrExtent2Di *>(this); }

  // member decl
  int32_t width;
  int32_t height;
};
static_assert(sizeof(Extent2Di) == sizeof(XrExtent2Di),
              "struct and wrapper have different size!");

struct Rect2Di {
  // ctor
  Rect2Di(const Offset2Di &offset_ = {}, const Extent2Di &extent_ = {})
      :

        offset{offset_}, extent{extent_} {}
  operator const XrRect2Di &() const {
    return *reinterpret_cast<const XrRect2Di *>(this);
  }
  operator XrRect2Di &() { return *reinterpret_cast<XrRect2Di *>(this); }

  // member decl
  Offset2Di offset;
  Extent2Di extent;
};
static_assert(sizeof(Rect2Di) == sizeof(XrRect2Di),
              "struct and wrapper have different size!");

struct SwapchainSubImage {
  // ctor
  SwapchainSubImage(const Swapchain &swapchain_ = {},
                    const Rect2Di &imageRect_ = {},
                    uint32_t imageArrayIndex_ = 0)
      :

        swapchain{swapchain_}, imageRect{imageRect_}, imageArrayIndex{
                                                          imageArrayIndex_} {}
  operator const XrSwapchainSubImage &() const {
    return *reinterpret_cast<const XrSwapchainSubImage *>(this);
  }
  operator XrSwapchainSubImage &() {
    return *reinterpret_cast<XrSwapchainSubImage *>(this);
  }

  // member decl
  Swapchain swapchain;
  Rect2Di imageRect;
  uint32_t imageArrayIndex;
};
static_assert(sizeof(SwapchainSubImage) == sizeof(XrSwapchainSubImage),
              "struct and wrapper have different size!");

struct CompositionLayerProjectionView
    : public traits::TypedStructTraits<CompositionLayerProjectionView> {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerProjectionView>;

public:
  // ctor
  CompositionLayerProjectionView(const Posef &pose_ = {}, const Fovf &fov_ = {},
                                 const SwapchainSubImage &subImage_ = {})
      :

        Parent(StructureType::CompositionLayerProjectionView),

        pose{pose_}, fov{fov_}, subImage{subImage_} {}
  operator const XrCompositionLayerProjectionView &() const {
    return *reinterpret_cast<const XrCompositionLayerProjectionView *>(this);
  }
  operator XrCompositionLayerProjectionView &() {
    return *reinterpret_cast<XrCompositionLayerProjectionView *>(this);
  }

  // member decl
  Posef pose;
  Fovf fov;
  SwapchainSubImage subImage;
};
static_assert(sizeof(CompositionLayerProjectionView) ==
                  sizeof(XrCompositionLayerProjectionView),
              "struct and wrapper have different size!");

struct CompositionLayerProjection
    : public traits::TypedStructTraits<CompositionLayerProjection> {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerProjection>;

public:
  // ctor
  CompositionLayerProjection(
      const CompositionLayerFlags &layerFlags_ = {}, const Space &space_ = {},
      uint32_t viewCount_ = 0,
      const CompositionLayerProjectionView *views_ = nullptr)
      :

        Parent(StructureType::CompositionLayerProjection),

        layerFlags{layerFlags_}, space{space_}, viewCount{viewCount_},
        views{views_} {}
  operator const XrCompositionLayerProjection &() const {
    return *reinterpret_cast<const XrCompositionLayerProjection *>(this);
  }
  operator XrCompositionLayerProjection &() {
    return *reinterpret_cast<XrCompositionLayerProjection *>(this);
  }

  // member decl
  CompositionLayerFlags layerFlags;
  Space space;
  uint32_t viewCount;
  const CompositionLayerProjectionView *views;
};
static_assert(sizeof(CompositionLayerProjection) ==
                  sizeof(XrCompositionLayerProjection),
              "struct and wrapper have different size!");

struct CompositionLayerQuad
    : public traits::TypedStructTraits<CompositionLayerQuad> {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerQuad>;

public:
  // ctor
  CompositionLayerQuad(const CompositionLayerFlags &layerFlags_ = {},
                       const Space &space_ = {},
                       const EyeVisibility &eyeVisibility_ = {},
                       const SwapchainSubImage &subImage_ = {},
                       const Posef &pose_ = {}, const Extent2Df &size_ = {})
      :

        Parent(StructureType::CompositionLayerQuad),

        layerFlags{layerFlags_}, space{space_}, eyeVisibility{eyeVisibility_},
        subImage{subImage_}, pose{pose_}, size{size_} {}
  operator const XrCompositionLayerQuad &() const {
    return *reinterpret_cast<const XrCompositionLayerQuad *>(this);
  }
  operator XrCompositionLayerQuad &() {
    return *reinterpret_cast<XrCompositionLayerQuad *>(this);
  }

  // member decl
  CompositionLayerFlags layerFlags;
  Space space;
  EyeVisibility eyeVisibility;
  SwapchainSubImage subImage;
  Posef pose;
  Extent2Df size;
};
static_assert(sizeof(CompositionLayerQuad) == sizeof(XrCompositionLayerQuad),
              "struct and wrapper have different size!");

struct EventDataEventsLost
    : public traits::TypedStructTraits<EventDataEventsLost> {
private:
  using Parent = traits::TypedStructTraits<EventDataEventsLost>;

public:
  // ctor
  EventDataEventsLost(uint32_t lostEventCount_ = 0)
      :

        Parent(StructureType::EventDataEventsLost),

        lostEventCount{lostEventCount_} {}
  operator const XrEventDataEventsLost &() const {
    return *reinterpret_cast<const XrEventDataEventsLost *>(this);
  }
  operator XrEventDataEventsLost &() {
    return *reinterpret_cast<XrEventDataEventsLost *>(this);
  }

  // member decl
  uint32_t lostEventCount;
};
static_assert(sizeof(EventDataEventsLost) == sizeof(XrEventDataEventsLost),
              "struct and wrapper have different size!");

struct EventDataInstanceLossPending
    : public traits::TypedStructTraits<EventDataInstanceLossPending> {
private:
  using Parent = traits::TypedStructTraits<EventDataInstanceLossPending>;

public:
  // ctor
  EventDataInstanceLossPending(const Time &lossTime_ = {})
      :

        Parent(StructureType::EventDataInstanceLossPending),

        lossTime{lossTime_} {}
  operator const XrEventDataInstanceLossPending &() const {
    return *reinterpret_cast<const XrEventDataInstanceLossPending *>(this);
  }
  operator XrEventDataInstanceLossPending &() {
    return *reinterpret_cast<XrEventDataInstanceLossPending *>(this);
  }

  // member decl
  Time lossTime;
};
static_assert(sizeof(EventDataInstanceLossPending) ==
                  sizeof(XrEventDataInstanceLossPending),
              "struct and wrapper have different size!");

struct EventDataSessionStateChanged
    : public traits::TypedStructTraits<EventDataSessionStateChanged> {
private:
  using Parent = traits::TypedStructTraits<EventDataSessionStateChanged>;

public:
  // ctor
  EventDataSessionStateChanged(const Session &session_ = {},
                               const SessionState &state_ = {},
                               const Time &time_ = {})
      :

        Parent(StructureType::EventDataSessionStateChanged),

        session{session_}, state{state_}, time{time_} {}
  operator const XrEventDataSessionStateChanged &() const {
    return *reinterpret_cast<const XrEventDataSessionStateChanged *>(this);
  }
  operator XrEventDataSessionStateChanged &() {
    return *reinterpret_cast<XrEventDataSessionStateChanged *>(this);
  }

  // member decl
  Session session;
  SessionState state;
  Time time;
};
static_assert(sizeof(EventDataSessionStateChanged) ==
                  sizeof(XrEventDataSessionStateChanged),
              "struct and wrapper have different size!");

struct EventDataReferenceSpaceChangePending
    : public traits::TypedStructTraits<EventDataReferenceSpaceChangePending> {
private:
  using Parent =
      traits::TypedStructTraits<EventDataReferenceSpaceChangePending>;

public:
  // ctor
  EventDataReferenceSpaceChangePending(
      const Session &session_ = {},
      const ReferenceSpaceType &referenceSpaceType_ = {},
      const Time &changeTime_ = {}, const Bool32 &poseValid_ = XR_FALSE,
      const Posef &poseInPreviousSpace_ = {})
      :

        Parent(StructureType::EventDataReferenceSpaceChangePending),

        session{session_}, referenceSpaceType{referenceSpaceType_},
        changeTime{changeTime_}, poseValid{poseValid_},
        poseInPreviousSpace{poseInPreviousSpace_} {}
  operator const XrEventDataReferenceSpaceChangePending &() const {
    return *reinterpret_cast<const XrEventDataReferenceSpaceChangePending *>(
        this);
  }
  operator XrEventDataReferenceSpaceChangePending &() {
    return *reinterpret_cast<XrEventDataReferenceSpaceChangePending *>(this);
  }

  // member decl
  Session session;
  ReferenceSpaceType referenceSpaceType;
  Time changeTime;
  Bool32 poseValid;
  Posef poseInPreviousSpace;
};
static_assert(sizeof(EventDataReferenceSpaceChangePending) ==
                  sizeof(XrEventDataReferenceSpaceChangePending),
              "struct and wrapper have different size!");

struct EventDataInteractionProfileChanged
    : public traits::TypedStructTraits<EventDataInteractionProfileChanged> {
private:
  using Parent = traits::TypedStructTraits<EventDataInteractionProfileChanged>;

public:
  // ctor
  EventDataInteractionProfileChanged(const Session &session_ = {})
      :

        Parent(StructureType::EventDataInteractionProfileChanged),

        session{session_} {}
  operator const XrEventDataInteractionProfileChanged &() const {
    return *reinterpret_cast<const XrEventDataInteractionProfileChanged *>(
        this);
  }
  operator XrEventDataInteractionProfileChanged &() {
    return *reinterpret_cast<XrEventDataInteractionProfileChanged *>(this);
  }

  // member decl
  Session session;
};
static_assert(sizeof(EventDataInteractionProfileChanged) ==
                  sizeof(XrEventDataInteractionProfileChanged),
              "struct and wrapper have different size!");

struct HapticVibration : public traits::TypedStructTraits<HapticVibration> {
private:
  using Parent = traits::TypedStructTraits<HapticVibration>;

public:
  // ctor
  HapticVibration(const Duration &duration_ = {}, float frequency_ = 0.0f,
                  float amplitude_ = 0.0f)
      :

        Parent(StructureType::HapticVibration),

        duration{duration_}, frequency{frequency_}, amplitude{amplitude_} {}
  operator const XrHapticVibration &() const {
    return *reinterpret_cast<const XrHapticVibration *>(this);
  }
  operator XrHapticVibration &() {
    return *reinterpret_cast<XrHapticVibration *>(this);
  }

  // member decl
  Duration duration;
  float frequency;
  float amplitude;
};
static_assert(sizeof(HapticVibration) == sizeof(XrHapticVibration),
              "struct and wrapper have different size!");

struct Offset2Df {
  // ctor
  Offset2Df(float x_ = 0.0f, float y_ = 0.0f)
      :

        x{x_}, y{y_} {}
  operator const XrOffset2Df &() const {
    return *reinterpret_cast<const XrOffset2Df *>(this);
  }
  operator XrOffset2Df &() { return *reinterpret_cast<XrOffset2Df *>(this); }

  // member decl
  float x;
  float y;
};
static_assert(sizeof(Offset2Df) == sizeof(XrOffset2Df),
              "struct and wrapper have different size!");

struct Rect2Df {
  // ctor
  Rect2Df(const Offset2Df &offset_ = {}, const Extent2Df &extent_ = {})
      :

        offset{offset_}, extent{extent_} {}
  operator const XrRect2Df &() const {
    return *reinterpret_cast<const XrRect2Df *>(this);
  }
  operator XrRect2Df &() { return *reinterpret_cast<XrRect2Df *>(this); }

  // member decl
  Offset2Df offset;
  Extent2Df extent;
};
static_assert(sizeof(Rect2Df) == sizeof(XrRect2Df),
              "struct and wrapper have different size!");

struct Vector4f {
  // ctor
  Vector4f(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f, float w_ = 0.0f)
      :

        x{x_}, y{y_}, z{z_}, w{w_} {}
  operator const XrVector4f &() const {
    return *reinterpret_cast<const XrVector4f *>(this);
  }
  operator XrVector4f &() { return *reinterpret_cast<XrVector4f *>(this); }

  // member decl
  float x;
  float y;
  float z;
  float w;
};
static_assert(sizeof(Vector4f) == sizeof(XrVector4f),
              "struct and wrapper have different size!");

struct Color4f {
  // ctor
  Color4f(float r_ = 0.0f, float g_ = 0.0f, float b_ = 0.0f, float a_ = 0.0f)
      :

        r{r_}, g{g_}, b{b_}, a{a_} {}
  operator const XrColor4f &() const {
    return *reinterpret_cast<const XrColor4f *>(this);
  }
  operator XrColor4f &() { return *reinterpret_cast<XrColor4f *>(this); }

  // member decl
  float r;
  float g;
  float b;
  float a;
};
static_assert(sizeof(Color4f) == sizeof(XrColor4f),
              "struct and wrapper have different size!");

struct CompositionLayerCubeKHR
    : public traits::TypedStructTraits<CompositionLayerCubeKHR> {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerCubeKHR>;

public:
  // ctor
  CompositionLayerCubeKHR(const CompositionLayerFlags &layerFlags_ = {},
                          const Space &space_ = {},
                          const EyeVisibility &eyeVisibility_ = {},
                          const Swapchain &swapchain_ = {},
                          uint32_t imageArrayIndex_ = 0,
                          const Quaternionf &orientation_ = {})
      :

        Parent(StructureType::CompositionLayerCubeKHR),

        layerFlags{layerFlags_}, space{space_},
        eyeVisibility{eyeVisibility_}, swapchain{swapchain_},
        imageArrayIndex{imageArrayIndex_}, orientation{orientation_} {}
  operator const XrCompositionLayerCubeKHR &() const {
    return *reinterpret_cast<const XrCompositionLayerCubeKHR *>(this);
  }
  operator XrCompositionLayerCubeKHR &() {
    return *reinterpret_cast<XrCompositionLayerCubeKHR *>(this);
  }

  // member decl
  CompositionLayerFlags layerFlags;
  Space space;
  EyeVisibility eyeVisibility;
  Swapchain swapchain;
  uint32_t imageArrayIndex;
  Quaternionf orientation;
};
static_assert(sizeof(CompositionLayerCubeKHR) ==
                  sizeof(XrCompositionLayerCubeKHR),
              "struct and wrapper have different size!");

#if defined(XR_USE_PLATFORM_ANDROID)
struct InstanceCreateInfoAndroidKHR
    : public traits::TypedStructTraits<InstanceCreateInfoAndroidKHR> {
private:
  using Parent = traits::TypedStructTraits<InstanceCreateInfoAndroidKHR>;

public:
  // ctor
  InstanceCreateInfoAndroidKHR(
      void *XR_MAY_ALIAS applicationVM_ = nullptr,
      void *XR_MAY_ALIAS applicationActivity_ = nullptr)
      :

        Parent(StructureType::InstanceCreateInfoAndroidKHR),

        applicationVM{applicationVM_}, applicationActivity{
                                           applicationActivity_} {}
  operator const XrInstanceCreateInfoAndroidKHR &() const {
    return *reinterpret_cast<const XrInstanceCreateInfoAndroidKHR *>(this);
  }
  operator XrInstanceCreateInfoAndroidKHR &() {
    return *reinterpret_cast<XrInstanceCreateInfoAndroidKHR *>(this);
  }

  // member decl
  void *XR_MAY_ALIAS applicationVM;
  void *XR_MAY_ALIAS applicationActivity;
};
static_assert(sizeof(InstanceCreateInfoAndroidKHR) ==
                  sizeof(XrInstanceCreateInfoAndroidKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_PLATFORM_ANDROID)

    struct CompositionLayerDepthInfoKHR : public traits::TypedStructTraits <
    CompositionLayerDepthInfoKHR > {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerDepthInfoKHR>;

public:
  // ctor
  CompositionLayerDepthInfoKHR(const SwapchainSubImage &subImage_ = {},
                               float minDepth_ = 0.0f, float maxDepth_ = 0.0f,
                               float nearZ_ = 0.0f, float farZ_ = 0.0f)
      :

        Parent(StructureType::CompositionLayerDepthInfoKHR),

        subImage{subImage_}, minDepth{minDepth_}, maxDepth{maxDepth_},
        nearZ{nearZ_}, farZ{farZ_} {}
  operator const XrCompositionLayerDepthInfoKHR &() const {
    return *reinterpret_cast<const XrCompositionLayerDepthInfoKHR *>(this);
  }
  operator XrCompositionLayerDepthInfoKHR &() {
    return *reinterpret_cast<XrCompositionLayerDepthInfoKHR *>(this);
  }

  // member decl
  SwapchainSubImage subImage;
  float minDepth;
  float maxDepth;
  float nearZ;
  float farZ;
};
static_assert(sizeof(CompositionLayerDepthInfoKHR) ==
                  sizeof(XrCompositionLayerDepthInfoKHR),
              "struct and wrapper have different size!");

#if defined(XR_USE_GRAPHICS_API_VULKAN)
struct VulkanSwapchainFormatListCreateInfoKHR
    : public traits::TypedStructTraits<VulkanSwapchainFormatListCreateInfoKHR> {
private:
  using Parent =
      traits::TypedStructTraits<VulkanSwapchainFormatListCreateInfoKHR>;

public:
  // ctor
  VulkanSwapchainFormatListCreateInfoKHR(uint32_t viewFormatCount_ = 0,
                                         const VkFormat *viewFormats_ = nullptr)
      :

        Parent(StructureType::VulkanSwapchainFormatListCreateInfoKHR),

        viewFormatCount{viewFormatCount_}, viewFormats{viewFormats_} {}
  operator const XrVulkanSwapchainFormatListCreateInfoKHR &() const {
    return *reinterpret_cast<const XrVulkanSwapchainFormatListCreateInfoKHR *>(
        this);
  }
  operator XrVulkanSwapchainFormatListCreateInfoKHR &() {
    return *reinterpret_cast<XrVulkanSwapchainFormatListCreateInfoKHR *>(this);
  }

  // member decl
  uint32_t viewFormatCount;
  const VkFormat *viewFormats;
};
static_assert(sizeof(VulkanSwapchainFormatListCreateInfoKHR) ==
                  sizeof(XrVulkanSwapchainFormatListCreateInfoKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

    struct CompositionLayerCylinderKHR : public traits::TypedStructTraits <
    CompositionLayerCylinderKHR > {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerCylinderKHR>;

public:
  // ctor
  CompositionLayerCylinderKHR(const CompositionLayerFlags &layerFlags_ = {},
                              const Space &space_ = {},
                              const EyeVisibility &eyeVisibility_ = {},
                              const SwapchainSubImage &subImage_ = {},
                              const Posef &pose_ = {}, float radius_ = 0.0f,
                              float centralAngle_ = 0.0f,
                              float aspectRatio_ = 0.0f)
      :

        Parent(StructureType::CompositionLayerCylinderKHR),

        layerFlags{layerFlags_}, space{space_}, eyeVisibility{eyeVisibility_},
        subImage{subImage_}, pose{pose_}, radius{radius_},
        centralAngle{centralAngle_}, aspectRatio{aspectRatio_} {}
  operator const XrCompositionLayerCylinderKHR &() const {
    return *reinterpret_cast<const XrCompositionLayerCylinderKHR *>(this);
  }
  operator XrCompositionLayerCylinderKHR &() {
    return *reinterpret_cast<XrCompositionLayerCylinderKHR *>(this);
  }

  // member decl
  CompositionLayerFlags layerFlags;
  Space space;
  EyeVisibility eyeVisibility;
  SwapchainSubImage subImage;
  Posef pose;
  float radius;
  float centralAngle;
  float aspectRatio;
};
static_assert(sizeof(CompositionLayerCylinderKHR) ==
                  sizeof(XrCompositionLayerCylinderKHR),
              "struct and wrapper have different size!");

struct CompositionLayerEquirectKHR
    : public traits::TypedStructTraits<CompositionLayerEquirectKHR> {
private:
  using Parent = traits::TypedStructTraits<CompositionLayerEquirectKHR>;

public:
  // ctor
  CompositionLayerEquirectKHR(const CompositionLayerFlags &layerFlags_ = {},
                              const Space &space_ = {},
                              const EyeVisibility &eyeVisibility_ = {},
                              const SwapchainSubImage &subImage_ = {},
                              const Posef &pose_ = {}, float radius_ = 0.0f,
                              const Vector2f &scale_ = {},
                              const Vector2f &bias_ = {})
      :

        Parent(StructureType::CompositionLayerEquirectKHR),

        layerFlags{layerFlags_}, space{space_},
        eyeVisibility{eyeVisibility_}, subImage{subImage_}, pose{pose_},
        radius{radius_}, scale{scale_}, bias{bias_} {}
  operator const XrCompositionLayerEquirectKHR &() const {
    return *reinterpret_cast<const XrCompositionLayerEquirectKHR *>(this);
  }
  operator XrCompositionLayerEquirectKHR &() {
    return *reinterpret_cast<XrCompositionLayerEquirectKHR *>(this);
  }

  // member decl
  CompositionLayerFlags layerFlags;
  Space space;
  EyeVisibility eyeVisibility;
  SwapchainSubImage subImage;
  Posef pose;
  float radius;
  Vector2f scale;
  Vector2f bias;
};
static_assert(sizeof(CompositionLayerEquirectKHR) ==
                  sizeof(XrCompositionLayerEquirectKHR),
              "struct and wrapper have different size!");

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
struct GraphicsBindingOpenGLWin32KHR
    : public traits::TypedStructTraits<GraphicsBindingOpenGLWin32KHR> {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingOpenGLWin32KHR>;

public:
  // ctor
  GraphicsBindingOpenGLWin32KHR(HDC hDC_ = {}, HGLRC hGLRC_ = {})
      :

        Parent(StructureType::GraphicsBindingOpenglWin32KHR),

        hDC{hDC_}, hGLRC{hGLRC_} {}
  operator const XrGraphicsBindingOpenGLWin32KHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR *>(this);
  }
  operator XrGraphicsBindingOpenGLWin32KHR &() {
    return *reinterpret_cast<XrGraphicsBindingOpenGLWin32KHR *>(this);
  }

  // member decl
  HDC hDC;
  HGLRC hGLRC;
};
static_assert(sizeof(GraphicsBindingOpenGLWin32KHR) ==
                  sizeof(XrGraphicsBindingOpenGLWin32KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
    struct GraphicsBindingOpenGLXlibKHR : public traits::TypedStructTraits <
    GraphicsBindingOpenGLXlibKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingOpenGLXlibKHR>;

public:
  // ctor
  GraphicsBindingOpenGLXlibKHR(Display *xDisplay_ = nullptr,
                               uint32_t visualid_ = 0,
                               GLXFBConfig glxFBConfig_ = {},
                               GLXDrawable glxDrawable_ = {},
                               GLXContext glxContext_ = {})
      :

        Parent(StructureType::GraphicsBindingOpenglXlibKHR),

        xDisplay{xDisplay_}, visualid{visualid_}, glxFBConfig{glxFBConfig_},
        glxDrawable{glxDrawable_}, glxContext{glxContext_} {}
  operator const XrGraphicsBindingOpenGLXlibKHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR *>(this);
  }
  operator XrGraphicsBindingOpenGLXlibKHR &() {
    return *reinterpret_cast<XrGraphicsBindingOpenGLXlibKHR *>(this);
  }

  // member decl
  Display *xDisplay;
  uint32_t visualid;
  GLXFBConfig glxFBConfig;
  GLXDrawable glxDrawable;
  GLXContext glxContext;
};
static_assert(sizeof(GraphicsBindingOpenGLXlibKHR) ==
                  sizeof(XrGraphicsBindingOpenGLXlibKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
    struct GraphicsBindingOpenGLXcbKHR : public traits::TypedStructTraits <
    GraphicsBindingOpenGLXcbKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingOpenGLXcbKHR>;

public:
  // ctor
  GraphicsBindingOpenGLXcbKHR(xcb_connection_t *connection_ = {},
                              uint32_t screenNumber_ = 0,
                              xcb_glx_fbconfig_t fbconfigid_ = {},
                              xcb_visualid_t visualid_ = {},
                              xcb_glx_drawable_t glxDrawable_ = {},
                              xcb_glx_context_t glxContext_ = {})
      :

        Parent(StructureType::GraphicsBindingOpenglXcbKHR),

        connection{connection_}, screenNumber{screenNumber_},
        fbconfigid{fbconfigid_}, visualid{visualid_}, glxDrawable{glxDrawable_},
        glxContext{glxContext_} {}
  operator const XrGraphicsBindingOpenGLXcbKHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR *>(this);
  }
  operator XrGraphicsBindingOpenGLXcbKHR &() {
    return *reinterpret_cast<XrGraphicsBindingOpenGLXcbKHR *>(this);
  }

  // member decl
  xcb_connection_t *connection;
  uint32_t screenNumber;
  xcb_glx_fbconfig_t fbconfigid;
  xcb_visualid_t visualid;
  xcb_glx_drawable_t glxDrawable;
  xcb_glx_context_t glxContext;
};
static_assert(sizeof(GraphicsBindingOpenGLXcbKHR) ==
                  sizeof(XrGraphicsBindingOpenGLXcbKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
    struct GraphicsBindingOpenGLWaylandKHR : public traits::TypedStructTraits <
    GraphicsBindingOpenGLWaylandKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingOpenGLWaylandKHR>;

public:
  // ctor
  GraphicsBindingOpenGLWaylandKHR(struct wl_display *display_ = {})
      :

        Parent(StructureType::GraphicsBindingOpenglWaylandKHR),

        display{display_} {}
  operator const XrGraphicsBindingOpenGLWaylandKHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR *>(this);
  }
  operator XrGraphicsBindingOpenGLWaylandKHR &() {
    return *reinterpret_cast<XrGraphicsBindingOpenGLWaylandKHR *>(this);
  }

  // member decl
  struct wl_display *display;
};
static_assert(sizeof(GraphicsBindingOpenGLWaylandKHR) ==
                  sizeof(XrGraphicsBindingOpenGLWaylandKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL) &&
       // defined(XR_USE_PLATFORM_WAYLAND)

#if defined(XR_USE_GRAPHICS_API_OPENGL)
    struct SwapchainImageOpenGLKHR : public traits::TypedStructTraits <
    SwapchainImageOpenGLKHR > {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageOpenGLKHR>;

public:
  // ctor
  SwapchainImageOpenGLKHR(uint32_t image_ = 0)
      :

        Parent(StructureType::SwapchainImageOpenglKHR),

        image{image_} {}
  operator const XrSwapchainImageOpenGLKHR &() const {
    return *reinterpret_cast<const XrSwapchainImageOpenGLKHR *>(this);
  }
  operator XrSwapchainImageOpenGLKHR &() {
    return *reinterpret_cast<XrSwapchainImageOpenGLKHR *>(this);
  }

  // member decl
  uint32_t image;
};
static_assert(sizeof(SwapchainImageOpenGLKHR) ==
                  sizeof(XrSwapchainImageOpenGLKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL)
    struct GraphicsRequirementsOpenGLKHR : public traits::TypedStructTraits <
    GraphicsRequirementsOpenGLKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsRequirementsOpenGLKHR>;

public:
  // ctor
  GraphicsRequirementsOpenGLKHR(const Version &minApiVersionSupported_ = {},
                                const Version &maxApiVersionSupported_ = {})
      :

        Parent(StructureType::GraphicsRequirementsOpenglKHR),

        minApiVersionSupported{minApiVersionSupported_},
        maxApiVersionSupported{maxApiVersionSupported_} {}
  operator const XrGraphicsRequirementsOpenGLKHR &() const {
    return *reinterpret_cast<const XrGraphicsRequirementsOpenGLKHR *>(this);
  }
  operator XrGraphicsRequirementsOpenGLKHR &() {
    return *reinterpret_cast<XrGraphicsRequirementsOpenGLKHR *>(this);
  }

  // member decl
  Version minApiVersionSupported;
  Version maxApiVersionSupported;
};
static_assert(sizeof(GraphicsRequirementsOpenGLKHR) ==
                  sizeof(XrGraphicsRequirementsOpenGLKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
    struct GraphicsBindingOpenGLESAndroidKHR : public traits::
        TypedStructTraits < GraphicsBindingOpenGLESAndroidKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingOpenGLESAndroidKHR>;

public:
  // ctor
  GraphicsBindingOpenGLESAndroidKHR(EGLDisplay display_ = {},
                                    EGLConfig config_ = {},
                                    EGLContext context_ = {})
      :

        Parent(StructureType::GraphicsBindingOpenglEsAndroidKHR),

        display{display_}, config{config_}, context{context_} {}
  operator const XrGraphicsBindingOpenGLESAndroidKHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR *>(this);
  }
  operator XrGraphicsBindingOpenGLESAndroidKHR &() {
    return *reinterpret_cast<XrGraphicsBindingOpenGLESAndroidKHR *>(this);
  }

  // member decl
  EGLDisplay display;
  EGLConfig config;
  EGLContext context;
};
static_assert(sizeof(GraphicsBindingOpenGLESAndroidKHR) ==
                  sizeof(XrGraphicsBindingOpenGLESAndroidKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES) &&
       // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
    struct SwapchainImageOpenGLESKHR : public traits::TypedStructTraits <
    SwapchainImageOpenGLESKHR > {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageOpenGLESKHR>;

public:
  // ctor
  SwapchainImageOpenGLESKHR(uint32_t image_ = 0)
      :

        Parent(StructureType::SwapchainImageOpenglEsKHR),

        image{image_} {}
  operator const XrSwapchainImageOpenGLESKHR &() const {
    return *reinterpret_cast<const XrSwapchainImageOpenGLESKHR *>(this);
  }
  operator XrSwapchainImageOpenGLESKHR &() {
    return *reinterpret_cast<XrSwapchainImageOpenGLESKHR *>(this);
  }

  // member decl
  uint32_t image;
};
static_assert(sizeof(SwapchainImageOpenGLESKHR) ==
                  sizeof(XrSwapchainImageOpenGLESKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
    struct GraphicsRequirementsOpenGLESKHR : public traits::TypedStructTraits <
    GraphicsRequirementsOpenGLESKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsRequirementsOpenGLESKHR>;

public:
  // ctor
  GraphicsRequirementsOpenGLESKHR(const Version &minApiVersionSupported_ = {},
                                  const Version &maxApiVersionSupported_ = {})
      :

        Parent(StructureType::GraphicsRequirementsOpenglEsKHR),

        minApiVersionSupported{minApiVersionSupported_},
        maxApiVersionSupported{maxApiVersionSupported_} {}
  operator const XrGraphicsRequirementsOpenGLESKHR &() const {
    return *reinterpret_cast<const XrGraphicsRequirementsOpenGLESKHR *>(this);
  }
  operator XrGraphicsRequirementsOpenGLESKHR &() {
    return *reinterpret_cast<XrGraphicsRequirementsOpenGLESKHR *>(this);
  }

  // member decl
  Version minApiVersionSupported;
  Version maxApiVersionSupported;
};
static_assert(sizeof(GraphicsRequirementsOpenGLESKHR) ==
                  sizeof(XrGraphicsRequirementsOpenGLESKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
    struct GraphicsBindingVulkanKHR : public traits::TypedStructTraits <
    GraphicsBindingVulkanKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingVulkanKHR>;

public:
  // ctor
  GraphicsBindingVulkanKHR(VkInstance instance_ = {},
                           VkPhysicalDevice physicalDevice_ = {},
                           VkDevice device_ = {},
                           uint32_t queueFamilyIndex_ = 0,
                           uint32_t queueIndex_ = 0)
      :

        Parent(StructureType::GraphicsBindingVulkanKHR),

        instance{instance_}, physicalDevice{physicalDevice_}, device{device_},
        queueFamilyIndex{queueFamilyIndex_}, queueIndex{queueIndex_} {}
  operator const XrGraphicsBindingVulkanKHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingVulkanKHR *>(this);
  }
  operator XrGraphicsBindingVulkanKHR &() {
    return *reinterpret_cast<XrGraphicsBindingVulkanKHR *>(this);
  }

  // member decl
  VkInstance instance;
  VkPhysicalDevice physicalDevice;
  VkDevice device;
  uint32_t queueFamilyIndex;
  uint32_t queueIndex;
};
static_assert(sizeof(GraphicsBindingVulkanKHR) ==
                  sizeof(XrGraphicsBindingVulkanKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
    struct SwapchainImageVulkanKHR : public traits::TypedStructTraits <
    SwapchainImageVulkanKHR > {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageVulkanKHR>;

public:
  // ctor
  SwapchainImageVulkanKHR(VkImage image_ = {})
      :

        Parent(StructureType::SwapchainImageVulkanKHR),

        image{image_} {}
  operator const XrSwapchainImageVulkanKHR &() const {
    return *reinterpret_cast<const XrSwapchainImageVulkanKHR *>(this);
  }
  operator XrSwapchainImageVulkanKHR &() {
    return *reinterpret_cast<XrSwapchainImageVulkanKHR *>(this);
  }

  // member decl
  VkImage image;
};
static_assert(sizeof(SwapchainImageVulkanKHR) ==
                  sizeof(XrSwapchainImageVulkanKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
    struct GraphicsRequirementsVulkanKHR : public traits::TypedStructTraits <
    GraphicsRequirementsVulkanKHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsRequirementsVulkanKHR>;

public:
  // ctor
  GraphicsRequirementsVulkanKHR(const Version &minApiVersionSupported_ = {},
                                const Version &maxApiVersionSupported_ = {})
      :

        Parent(StructureType::GraphicsRequirementsVulkanKHR),

        minApiVersionSupported{minApiVersionSupported_},
        maxApiVersionSupported{maxApiVersionSupported_} {}
  operator const XrGraphicsRequirementsVulkanKHR &() const {
    return *reinterpret_cast<const XrGraphicsRequirementsVulkanKHR *>(this);
  }
  operator XrGraphicsRequirementsVulkanKHR &() {
    return *reinterpret_cast<XrGraphicsRequirementsVulkanKHR *>(this);
  }

  // member decl
  Version minApiVersionSupported;
  Version maxApiVersionSupported;
};
static_assert(sizeof(GraphicsRequirementsVulkanKHR) ==
                  sizeof(XrGraphicsRequirementsVulkanKHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)
    struct GraphicsBindingD3D11KHR : public traits::TypedStructTraits <
    GraphicsBindingD3D11KHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingD3D11KHR>;

public:
  // ctor
  GraphicsBindingD3D11KHR(ID3D11Device *device_ = nullptr)
      :

        Parent(StructureType::GraphicsBindingD3D11KHR),

        device{device_} {}
  operator const XrGraphicsBindingD3D11KHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingD3D11KHR *>(this);
  }
  operator XrGraphicsBindingD3D11KHR &() {
    return *reinterpret_cast<XrGraphicsBindingD3D11KHR *>(this);
  }

  // member decl
  ID3D11Device *device;
};
static_assert(sizeof(GraphicsBindingD3D11KHR) ==
                  sizeof(XrGraphicsBindingD3D11KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D11)
    struct SwapchainImageD3D11KHR : public traits::TypedStructTraits <
    SwapchainImageD3D11KHR > {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageD3D11KHR>;

public:
  // ctor
  SwapchainImageD3D11KHR(ID3D11Texture2D *texture_ = nullptr)
      :

        Parent(StructureType::SwapchainImageD3D11KHR),

        texture{texture_} {}
  operator const XrSwapchainImageD3D11KHR &() const {
    return *reinterpret_cast<const XrSwapchainImageD3D11KHR *>(this);
  }
  operator XrSwapchainImageD3D11KHR &() {
    return *reinterpret_cast<XrSwapchainImageD3D11KHR *>(this);
  }

  // member decl
  ID3D11Texture2D *texture;
};
static_assert(sizeof(SwapchainImageD3D11KHR) ==
                  sizeof(XrSwapchainImageD3D11KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D11)
    struct GraphicsRequirementsD3D11KHR : public traits::TypedStructTraits <
    GraphicsRequirementsD3D11KHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsRequirementsD3D11KHR>;

public:
  // ctor
  GraphicsRequirementsD3D11KHR(LUID adapterLuid_ = {},
                               D3D_FEATURE_LEVEL minFeatureLevel_ = {})
      :

        Parent(StructureType::GraphicsRequirementsD3D11KHR),

        adapterLuid{adapterLuid_}, minFeatureLevel{minFeatureLevel_} {}
  operator const XrGraphicsRequirementsD3D11KHR &() const {
    return *reinterpret_cast<const XrGraphicsRequirementsD3D11KHR *>(this);
  }
  operator XrGraphicsRequirementsD3D11KHR &() {
    return *reinterpret_cast<XrGraphicsRequirementsD3D11KHR *>(this);
  }

  // member decl
  LUID adapterLuid;
  D3D_FEATURE_LEVEL minFeatureLevel;
};
static_assert(sizeof(GraphicsRequirementsD3D11KHR) ==
                  sizeof(XrGraphicsRequirementsD3D11KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)
    struct GraphicsBindingD3D12KHR : public traits::TypedStructTraits <
    GraphicsBindingD3D12KHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsBindingD3D12KHR>;

public:
  // ctor
  GraphicsBindingD3D12KHR(ID3D12Device *device_ = nullptr,
                          ID3D12CommandQueue *queue_ = nullptr)
      :

        Parent(StructureType::GraphicsBindingD3D12KHR),

        device{device_}, queue{queue_} {}
  operator const XrGraphicsBindingD3D12KHR &() const {
    return *reinterpret_cast<const XrGraphicsBindingD3D12KHR *>(this);
  }
  operator XrGraphicsBindingD3D12KHR &() {
    return *reinterpret_cast<XrGraphicsBindingD3D12KHR *>(this);
  }

  // member decl
  ID3D12Device *device;
  ID3D12CommandQueue *queue;
};
static_assert(sizeof(GraphicsBindingD3D12KHR) ==
                  sizeof(XrGraphicsBindingD3D12KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D12)

#if defined(XR_USE_GRAPHICS_API_D3D12)
    struct SwapchainImageD3D12KHR : public traits::TypedStructTraits <
    SwapchainImageD3D12KHR > {
private:
  using Parent = traits::TypedStructTraits<SwapchainImageD3D12KHR>;

public:
  // ctor
  SwapchainImageD3D12KHR(ID3D12Resource *texture_ = nullptr)
      :

        Parent(StructureType::SwapchainImageD3D12KHR),

        texture{texture_} {}
  operator const XrSwapchainImageD3D12KHR &() const {
    return *reinterpret_cast<const XrSwapchainImageD3D12KHR *>(this);
  }
  operator XrSwapchainImageD3D12KHR &() {
    return *reinterpret_cast<XrSwapchainImageD3D12KHR *>(this);
  }

  // member decl
  ID3D12Resource *texture;
};
static_assert(sizeof(SwapchainImageD3D12KHR) ==
                  sizeof(XrSwapchainImageD3D12KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D12)

#if defined(XR_USE_GRAPHICS_API_D3D12)
    struct GraphicsRequirementsD3D12KHR : public traits::TypedStructTraits <
    GraphicsRequirementsD3D12KHR > {
private:
  using Parent = traits::TypedStructTraits<GraphicsRequirementsD3D12KHR>;

public:
  // ctor
  GraphicsRequirementsD3D12KHR(LUID adapterLuid_ = {},
                               D3D_FEATURE_LEVEL minFeatureLevel_ = {})
      :

        Parent(StructureType::GraphicsRequirementsD3D12KHR),

        adapterLuid{adapterLuid_}, minFeatureLevel{minFeatureLevel_} {}
  operator const XrGraphicsRequirementsD3D12KHR &() const {
    return *reinterpret_cast<const XrGraphicsRequirementsD3D12KHR *>(this);
  }
  operator XrGraphicsRequirementsD3D12KHR &() {
    return *reinterpret_cast<XrGraphicsRequirementsD3D12KHR *>(this);
  }

  // member decl
  LUID adapterLuid;
  D3D_FEATURE_LEVEL minFeatureLevel;
};
static_assert(sizeof(GraphicsRequirementsD3D12KHR) ==
                  sizeof(XrGraphicsRequirementsD3D12KHR),
              "struct and wrapper have different size!");
#endif // defined(XR_USE_GRAPHICS_API_D3D12)

    struct VisibilityMaskKHR : public traits::TypedStructTraits <
    VisibilityMaskKHR > {
private:
  using Parent = traits::TypedStructTraits<VisibilityMaskKHR>;

public:
  // ctor
  VisibilityMaskKHR(uint32_t vertexCapacityInput_ = 0,
                    uint32_t vertexCountOutput_ = 0,
                    Vector2f *vertices_ = nullptr,
                    uint32_t indexCapacityInput_ = 0,
                    uint32_t indexCountOutput_ = 0,
                    uint32_t *indices_ = nullptr)
      :

        Parent(StructureType::VisibilityMaskKHR),

        vertexCapacityInput{vertexCapacityInput_},
        vertexCountOutput{vertexCountOutput_}, vertices{vertices_},
        indexCapacityInput{indexCapacityInput_},
        indexCountOutput{indexCountOutput_}, indices{indices_} {}
  operator const XrVisibilityMaskKHR &() const {
    return *reinterpret_cast<const XrVisibilityMaskKHR *>(this);
  }
  operator XrVisibilityMaskKHR &() {
    return *reinterpret_cast<XrVisibilityMaskKHR *>(this);
  }

  // member decl
  uint32_t vertexCapacityInput;
  uint32_t vertexCountOutput;
  Vector2f *vertices;
  uint32_t indexCapacityInput;
  uint32_t indexCountOutput;
  uint32_t *indices;
};
static_assert(sizeof(VisibilityMaskKHR) == sizeof(XrVisibilityMaskKHR),
              "struct and wrapper have different size!");

struct EventDataVisibilityMaskChangedKHR
    : public traits::TypedStructTraits<EventDataVisibilityMaskChangedKHR> {
private:
  using Parent = traits::TypedStructTraits<EventDataVisibilityMaskChangedKHR>;

public:
  // ctor
  EventDataVisibilityMaskChangedKHR(
      const Session &session_ = {},
      const ViewConfigurationType &viewConfigurationType_ = {},
      uint32_t viewIndex_ = 0)
      :

        Parent(StructureType::EventDataVisibilityMaskChangedKHR),

        session{session_},
        viewConfigurationType{viewConfigurationType_}, viewIndex{viewIndex_} {}
  operator const XrEventDataVisibilityMaskChangedKHR &() const {
    return *reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR *>(this);
  }
  operator XrEventDataVisibilityMaskChangedKHR &() {
    return *reinterpret_cast<XrEventDataVisibilityMaskChangedKHR *>(this);
  }

  // member decl
  Session session;
  ViewConfigurationType viewConfigurationType;
  uint32_t viewIndex;
};
static_assert(sizeof(EventDataVisibilityMaskChangedKHR) ==
                  sizeof(XrEventDataVisibilityMaskChangedKHR),
              "struct and wrapper have different size!");

struct EventDataPerfSettingsEXT
    : public traits::TypedStructTraits<EventDataPerfSettingsEXT> {
private:
  using Parent = traits::TypedStructTraits<EventDataPerfSettingsEXT>;

public:
  // ctor
  EventDataPerfSettingsEXT(
      const PerfSettingsDomainEXT &domain_ = {},
      const PerfSettingsSubDomainEXT &subDomain_ = {},
      const PerfSettingsNotificationLevelEXT &fromLevel_ = {},
      const PerfSettingsNotificationLevelEXT &toLevel_ = {})
      :

        Parent(StructureType::EventDataPerfSettingsEXT),

        domain{domain_}, subDomain{subDomain_}, fromLevel{fromLevel_},
        toLevel{toLevel_} {}
  operator const XrEventDataPerfSettingsEXT &() const {
    return *reinterpret_cast<const XrEventDataPerfSettingsEXT *>(this);
  }
  operator XrEventDataPerfSettingsEXT &() {
    return *reinterpret_cast<XrEventDataPerfSettingsEXT *>(this);
  }

  // member decl
  PerfSettingsDomainEXT domain;
  PerfSettingsSubDomainEXT subDomain;
  PerfSettingsNotificationLevelEXT fromLevel;
  PerfSettingsNotificationLevelEXT toLevel;
};
static_assert(sizeof(EventDataPerfSettingsEXT) ==
                  sizeof(XrEventDataPerfSettingsEXT),
              "struct and wrapper have different size!");

struct DebugUtilsObjectNameInfoEXT
    : public traits::TypedStructTraits<DebugUtilsObjectNameInfoEXT> {
private:
  using Parent = traits::TypedStructTraits<DebugUtilsObjectNameInfoEXT>;

public:
  // ctor
  DebugUtilsObjectNameInfoEXT(const ObjectType &objectType_ = {},
                              uint64_t objectHandle_ = 0,
                              const char *objectName_ = nullptr)
      :

        Parent(StructureType::DebugUtilsObjectNameInfoEXT),

        objectType{objectType_}, objectHandle{objectHandle_},
        objectName{objectName_} {}
  operator const XrDebugUtilsObjectNameInfoEXT &() const {
    return *reinterpret_cast<const XrDebugUtilsObjectNameInfoEXT *>(this);
  }
  operator XrDebugUtilsObjectNameInfoEXT &() {
    return *reinterpret_cast<XrDebugUtilsObjectNameInfoEXT *>(this);
  }

  // member decl
  ObjectType objectType;
  uint64_t objectHandle;
  const char *objectName;
};
static_assert(sizeof(DebugUtilsObjectNameInfoEXT) ==
                  sizeof(XrDebugUtilsObjectNameInfoEXT),
              "struct and wrapper have different size!");

struct DebugUtilsLabelEXT
    : public traits::TypedStructTraits<DebugUtilsLabelEXT> {
private:
  using Parent = traits::TypedStructTraits<DebugUtilsLabelEXT>;

public:
  // ctor
  DebugUtilsLabelEXT(const char *labelName_ = nullptr)
      :

        Parent(StructureType::DebugUtilsLabelEXT),

        labelName{labelName_} {}
  operator const XrDebugUtilsLabelEXT &() const {
    return *reinterpret_cast<const XrDebugUtilsLabelEXT *>(this);
  }
  operator XrDebugUtilsLabelEXT &() {
    return *reinterpret_cast<XrDebugUtilsLabelEXT *>(this);
  }

  // member decl
  const char *labelName;
};
static_assert(sizeof(DebugUtilsLabelEXT) == sizeof(XrDebugUtilsLabelEXT),
              "struct and wrapper have different size!");

struct DebugUtilsMessengerCallbackDataEXT
    : public traits::TypedStructTraits<DebugUtilsMessengerCallbackDataEXT> {
private:
  using Parent = traits::TypedStructTraits<DebugUtilsMessengerCallbackDataEXT>;

public:
  // ctor
  DebugUtilsMessengerCallbackDataEXT(
      const char *messageId_ = nullptr, const char *functionName_ = nullptr,
      const char *message_ = nullptr, uint32_t objectCount_ = 0,
      DebugUtilsObjectNameInfoEXT *objects_ = nullptr,
      uint32_t sessionLabelCount_ = 0,
      DebugUtilsLabelEXT *sessionLabels_ = nullptr)
      :

        Parent(StructureType::DebugUtilsMessengerCallbackDataEXT),

        messageId{messageId_}, functionName{functionName_}, message{message_},
        objectCount{objectCount_}, objects{objects_},
        sessionLabelCount{sessionLabelCount_}, sessionLabels{sessionLabels_} {}
  operator const XrDebugUtilsMessengerCallbackDataEXT &() const {
    return *reinterpret_cast<const XrDebugUtilsMessengerCallbackDataEXT *>(
        this);
  }
  operator XrDebugUtilsMessengerCallbackDataEXT &() {
    return *reinterpret_cast<XrDebugUtilsMessengerCallbackDataEXT *>(this);
  }

  // member decl
  const char *messageId;
  const char *functionName;
  const char *message;
  uint32_t objectCount;
  DebugUtilsObjectNameInfoEXT *objects;
  uint32_t sessionLabelCount;
  DebugUtilsLabelEXT *sessionLabels;
};
static_assert(sizeof(DebugUtilsMessengerCallbackDataEXT) ==
                  sizeof(XrDebugUtilsMessengerCallbackDataEXT),
              "struct and wrapper have different size!");

struct DebugUtilsMessengerCreateInfoEXT
    : public traits::TypedStructTraits<DebugUtilsMessengerCreateInfoEXT> {
private:
  using Parent = traits::TypedStructTraits<DebugUtilsMessengerCreateInfoEXT>;

public:
  // ctor
  DebugUtilsMessengerCreateInfoEXT(
      const DebugUtilsMessageSeverityFlagsEXT &messageSeverities_ = {},
      const DebugUtilsMessageTypeFlagsEXT &messageTypes_ = {},
      PFN_xrDebugUtilsMessengerCallbackEXT userCallback_ = nullptr,
      void *XR_MAY_ALIAS userData_ = nullptr)
      :

        Parent(StructureType::DebugUtilsMessengerCreateInfoEXT),

        messageSeverities{messageSeverities_}, messageTypes{messageTypes_},
        userCallback{userCallback_}, userData{userData_} {}
  operator const XrDebugUtilsMessengerCreateInfoEXT &() const {
    return *reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT *>(this);
  }
  operator XrDebugUtilsMessengerCreateInfoEXT &() {
    return *reinterpret_cast<XrDebugUtilsMessengerCreateInfoEXT *>(this);
  }

  // member decl
  DebugUtilsMessageSeverityFlagsEXT messageSeverities;
  DebugUtilsMessageTypeFlagsEXT messageTypes;
  PFN_xrDebugUtilsMessengerCallbackEXT userCallback;
  void *XR_MAY_ALIAS userData;
};
static_assert(sizeof(DebugUtilsMessengerCreateInfoEXT) ==
                  sizeof(XrDebugUtilsMessengerCreateInfoEXT),
              "struct and wrapper have different size!");

struct SpatialAnchorCreateInfoMSFT
    : public traits::TypedStructTraits<SpatialAnchorCreateInfoMSFT> {
private:
  using Parent = traits::TypedStructTraits<SpatialAnchorCreateInfoMSFT>;

public:
  // ctor
  SpatialAnchorCreateInfoMSFT(const Space &space_ = {}, const Posef &pose_ = {},
                              const Time &time_ = {})
      :

        Parent(StructureType::SpatialAnchorCreateInfoMSFT),

        space{space_}, pose{pose_}, time{time_} {}
  operator const XrSpatialAnchorCreateInfoMSFT &() const {
    return *reinterpret_cast<const XrSpatialAnchorCreateInfoMSFT *>(this);
  }
  operator XrSpatialAnchorCreateInfoMSFT &() {
    return *reinterpret_cast<XrSpatialAnchorCreateInfoMSFT *>(this);
  }

  // member decl
  Space space;
  Posef pose;
  Time time;
};
static_assert(sizeof(SpatialAnchorCreateInfoMSFT) ==
                  sizeof(XrSpatialAnchorCreateInfoMSFT),
              "struct and wrapper have different size!");

struct SpatialAnchorSpaceCreateInfoMSFT
    : public traits::TypedStructTraits<SpatialAnchorSpaceCreateInfoMSFT> {
private:
  using Parent = traits::TypedStructTraits<SpatialAnchorSpaceCreateInfoMSFT>;

public:
  // ctor
  SpatialAnchorSpaceCreateInfoMSFT(const SpatialAnchorMSFT &anchor_ = {},
                                   const Posef &poseInAnchorSpace_ = {})
      :

        Parent(StructureType::SpatialAnchorSpaceCreateInfoMSFT),

        anchor{anchor_}, poseInAnchorSpace{poseInAnchorSpace_} {}
  operator const XrSpatialAnchorSpaceCreateInfoMSFT &() const {
    return *reinterpret_cast<const XrSpatialAnchorSpaceCreateInfoMSFT *>(this);
  }
  operator XrSpatialAnchorSpaceCreateInfoMSFT &() {
    return *reinterpret_cast<XrSpatialAnchorSpaceCreateInfoMSFT *>(this);
  }

  // member decl
  SpatialAnchorMSFT anchor;
  Posef poseInAnchorSpace;
};
static_assert(sizeof(SpatialAnchorSpaceCreateInfoMSFT) ==
                  sizeof(XrSpatialAnchorSpaceCreateInfoMSFT),
              "struct and wrapper have different size!");

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @brief Dispatch class for OpenXR that looks up all functions using a provided
 * or statically-available xrGetInstanceProcAddr function and the optional
 * Instance.
 *
 * This is safer to use, especially in large/multi-module applications, than
 * DispatchLoaderStatic, and is thus recommended.
 *
 * By default, it is lazy-populating: only populating a function pointer when it
 * is attempted to be called (if this object is not const). You can
 * early-populate it using the createFullyPopulated() factory method, providing
 * an Instance and optionally a xrGetInstanceProcAddr function pointer.
 *
 * This class stores all function pointers as type-erased PFN_xrVoidFunction,
 * casting at time of call. This allows the same memory representation to be
 * used across translation units that may not share the same platform defines.
 * Only the member function trampolines containing the casts are conditional on
 * platform defines.
 *
 * @ingroup dispatch
 */
class DispatchLoaderDynamic {
public:
  /*!
   * @name Constuctor/Factory functions
   * @{
   */
  /*!
   * @brief Create a lazy-populating dispatch table.
   *
   * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr
   * will be used.
   */
  explicit DispatchLoaderDynamic(
      Instance instance = nullptr,
      PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr)
      : m_instance(instance),
        pfnGetInstanceProcAddr(
            reinterpret_cast<PFN_xrVoidFunction>(getInstanceProcAddr)) {
    if (pfnGetInstanceProcAddr == nullptr) {
      pfnGetInstanceProcAddr =
          reinterpret_cast<PFN_xrVoidFunction>(&::xrGetInstanceProcAddr);
    }
  }

  /*!
   * @brief Create a fully-populated dispatch table given a non-null XrInstance
   * and an optional getInstanceProcAddr.
   *
   * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr
   * will be used.
   */
  static DispatchLoaderDynamic createFullyPopulated(
      Instance instance,
      PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr) {
    OPENXR_HPP_ASSERT(instance != nullptr);
    DispatchLoaderDynamic dispatch{instance, getInstanceProcAddr};
    dispatch.populate_("xrGetInstanceProcAddr",
                       dispatch.pfnGetInstanceProcAddr);
    dispatch.populate_("xrEnumerateApiLayerProperties",
                       dispatch.pfnEnumerateApiLayerProperties);
    dispatch.populate_("xrEnumerateInstanceExtensionProperties",
                       dispatch.pfnEnumerateInstanceExtensionProperties);
    dispatch.populate_("xrCreateInstance", dispatch.pfnCreateInstance);
    dispatch.populate_("xrDestroyInstance", dispatch.pfnDestroyInstance);
    dispatch.populate_("xrGetInstanceProperties",
                       dispatch.pfnGetInstanceProperties);
    dispatch.populate_("xrPollEvent", dispatch.pfnPollEvent);
    dispatch.populate_("xrResultToString", dispatch.pfnResultToString);
    dispatch.populate_("xrStructureTypeToString",
                       dispatch.pfnStructureTypeToString);
    dispatch.populate_("xrGetSystem", dispatch.pfnGetSystem);
    dispatch.populate_("xrGetSystemProperties",
                       dispatch.pfnGetSystemProperties);
    dispatch.populate_("xrEnumerateEnvironmentBlendModes",
                       dispatch.pfnEnumerateEnvironmentBlendModes);
    dispatch.populate_("xrCreateSession", dispatch.pfnCreateSession);
    dispatch.populate_("xrDestroySession", dispatch.pfnDestroySession);
    dispatch.populate_("xrEnumerateReferenceSpaces",
                       dispatch.pfnEnumerateReferenceSpaces);
    dispatch.populate_("xrCreateReferenceSpace",
                       dispatch.pfnCreateReferenceSpace);
    dispatch.populate_("xrGetReferenceSpaceBoundsRect",
                       dispatch.pfnGetReferenceSpaceBoundsRect);
    dispatch.populate_("xrCreateActionSpace", dispatch.pfnCreateActionSpace);
    dispatch.populate_("xrLocateSpace", dispatch.pfnLocateSpace);
    dispatch.populate_("xrDestroySpace", dispatch.pfnDestroySpace);
    dispatch.populate_("xrEnumerateViewConfigurations",
                       dispatch.pfnEnumerateViewConfigurations);
    dispatch.populate_("xrGetViewConfigurationProperties",
                       dispatch.pfnGetViewConfigurationProperties);
    dispatch.populate_("xrEnumerateViewConfigurationViews",
                       dispatch.pfnEnumerateViewConfigurationViews);
    dispatch.populate_("xrEnumerateSwapchainFormats",
                       dispatch.pfnEnumerateSwapchainFormats);
    dispatch.populate_("xrCreateSwapchain", dispatch.pfnCreateSwapchain);
    dispatch.populate_("xrDestroySwapchain", dispatch.pfnDestroySwapchain);
    dispatch.populate_("xrEnumerateSwapchainImages",
                       dispatch.pfnEnumerateSwapchainImages);
    dispatch.populate_("xrAcquireSwapchainImage",
                       dispatch.pfnAcquireSwapchainImage);
    dispatch.populate_("xrWaitSwapchainImage", dispatch.pfnWaitSwapchainImage);
    dispatch.populate_("xrReleaseSwapchainImage",
                       dispatch.pfnReleaseSwapchainImage);
    dispatch.populate_("xrBeginSession", dispatch.pfnBeginSession);
    dispatch.populate_("xrEndSession", dispatch.pfnEndSession);
    dispatch.populate_("xrRequestExitSession", dispatch.pfnRequestExitSession);
    dispatch.populate_("xrWaitFrame", dispatch.pfnWaitFrame);
    dispatch.populate_("xrBeginFrame", dispatch.pfnBeginFrame);
    dispatch.populate_("xrEndFrame", dispatch.pfnEndFrame);
    dispatch.populate_("xrLocateViews", dispatch.pfnLocateViews);
    dispatch.populate_("xrStringToPath", dispatch.pfnStringToPath);
    dispatch.populate_("xrPathToString", dispatch.pfnPathToString);
    dispatch.populate_("xrCreateActionSet", dispatch.pfnCreateActionSet);
    dispatch.populate_("xrDestroyActionSet", dispatch.pfnDestroyActionSet);
    dispatch.populate_("xrCreateAction", dispatch.pfnCreateAction);
    dispatch.populate_("xrDestroyAction", dispatch.pfnDestroyAction);
    dispatch.populate_("xrSuggestInteractionProfileBindings",
                       dispatch.pfnSuggestInteractionProfileBindings);
    dispatch.populate_("xrAttachSessionActionSets",
                       dispatch.pfnAttachSessionActionSets);
    dispatch.populate_("xrGetCurrentInteractionProfile",
                       dispatch.pfnGetCurrentInteractionProfile);
    dispatch.populate_("xrGetActionStateBoolean",
                       dispatch.pfnGetActionStateBoolean);
    dispatch.populate_("xrGetActionStateFloat",
                       dispatch.pfnGetActionStateFloat);
    dispatch.populate_("xrGetActionStateVector2f",
                       dispatch.pfnGetActionStateVector2f);
    dispatch.populate_("xrGetActionStatePose", dispatch.pfnGetActionStatePose);
    dispatch.populate_("xrSyncActions", dispatch.pfnSyncActions);
    dispatch.populate_("xrEnumerateBoundSourcesForAction",
                       dispatch.pfnEnumerateBoundSourcesForAction);
    dispatch.populate_("xrGetInputSourceLocalizedName",
                       dispatch.pfnGetInputSourceLocalizedName);
    dispatch.populate_("xrApplyHapticFeedback",
                       dispatch.pfnApplyHapticFeedback);
    dispatch.populate_("xrStopHapticFeedback", dispatch.pfnStopHapticFeedback);
    dispatch.populate_("xrSetAndroidApplicationThreadKHR",
                       dispatch.pfnSetAndroidApplicationThreadKHR);
    dispatch.populate_("xrCreateSwapchainAndroidSurfaceKHR",
                       dispatch.pfnCreateSwapchainAndroidSurfaceKHR);
    dispatch.populate_("xrGetOpenGLGraphicsRequirementsKHR",
                       dispatch.pfnGetOpenGLGraphicsRequirementsKHR);
    dispatch.populate_("xrGetOpenGLESGraphicsRequirementsKHR",
                       dispatch.pfnGetOpenGLESGraphicsRequirementsKHR);
    dispatch.populate_("xrGetVulkanInstanceExtensionsKHR",
                       dispatch.pfnGetVulkanInstanceExtensionsKHR);
    dispatch.populate_("xrGetVulkanDeviceExtensionsKHR",
                       dispatch.pfnGetVulkanDeviceExtensionsKHR);
    dispatch.populate_("xrGetVulkanGraphicsDeviceKHR",
                       dispatch.pfnGetVulkanGraphicsDeviceKHR);
    dispatch.populate_("xrGetVulkanGraphicsRequirementsKHR",
                       dispatch.pfnGetVulkanGraphicsRequirementsKHR);
    dispatch.populate_("xrGetD3D11GraphicsRequirementsKHR",
                       dispatch.pfnGetD3D11GraphicsRequirementsKHR);
    dispatch.populate_("xrGetD3D12GraphicsRequirementsKHR",
                       dispatch.pfnGetD3D12GraphicsRequirementsKHR);
    dispatch.populate_("xrGetVisibilityMaskKHR",
                       dispatch.pfnGetVisibilityMaskKHR);
    dispatch.populate_("xrConvertWin32PerformanceCounterToTimeKHR",
                       dispatch.pfnConvertWin32PerformanceCounterToTimeKHR);
    dispatch.populate_("xrConvertTimeToWin32PerformanceCounterKHR",
                       dispatch.pfnConvertTimeToWin32PerformanceCounterKHR);
    dispatch.populate_("xrConvertTimespecTimeToTimeKHR",
                       dispatch.pfnConvertTimespecTimeToTimeKHR);
    dispatch.populate_("xrConvertTimeToTimespecTimeKHR",
                       dispatch.pfnConvertTimeToTimespecTimeKHR);
    dispatch.populate_("xrPerfSettingsSetPerformanceLevelEXT",
                       dispatch.pfnPerfSettingsSetPerformanceLevelEXT);
    dispatch.populate_("xrThermalGetTemperatureTrendEXT",
                       dispatch.pfnThermalGetTemperatureTrendEXT);
    dispatch.populate_("xrSetDebugUtilsObjectNameEXT",
                       dispatch.pfnSetDebugUtilsObjectNameEXT);
    dispatch.populate_("xrCreateDebugUtilsMessengerEXT",
                       dispatch.pfnCreateDebugUtilsMessengerEXT);
    dispatch.populate_("xrDestroyDebugUtilsMessengerEXT",
                       dispatch.pfnDestroyDebugUtilsMessengerEXT);
    dispatch.populate_("xrSubmitDebugUtilsMessageEXT",
                       dispatch.pfnSubmitDebugUtilsMessageEXT);
    dispatch.populate_("xrSessionBeginDebugUtilsLabelRegionEXT",
                       dispatch.pfnSessionBeginDebugUtilsLabelRegionEXT);
    dispatch.populate_("xrSessionEndDebugUtilsLabelRegionEXT",
                       dispatch.pfnSessionEndDebugUtilsLabelRegionEXT);
    dispatch.populate_("xrSessionInsertDebugUtilsLabelEXT",
                       dispatch.pfnSessionInsertDebugUtilsLabelEXT);
    dispatch.populate_("xrCreateSpatialAnchorMSFT",
                       dispatch.pfnCreateSpatialAnchorMSFT);
    dispatch.populate_("xrCreateSpatialAnchorSpaceMSFT",
                       dispatch.pfnCreateSpatialAnchorSpaceMSFT);
    dispatch.populate_("xrDestroySpatialAnchorMSFT",
                       dispatch.pfnDestroySpatialAnchorMSFT);
    return dispatch;
  }

  //! @}

  /*!
   * @name Entry points
   * @brief These populate the function pointer (if required and non-const),
   * then cast it and call it.
   *
   * We store everything as PFN_xrVoidFunction to allow us to have the same
   * representation all over, despite containing function pointers that might
   * not be accessible without some platform defines. Thus, only our accessor
   * methods differ between different includes of this header, not our data
   * members.
   *
   * @{
   */

  //! @brief Call xrGetInstanceProcAddr, populating function pointer if
  //! required.
  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) {

    XrResult result =
        populate_("xrGetInstanceProcAddr", pfnGetInstanceProcAddr);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInstanceProcAddr>(
        pfnGetInstanceProcAddr))(instance, name, function);
  }

  //! @brief Call xrGetInstanceProcAddr (const overload - does not populate
  //! function pointer)
  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) const {

    return (reinterpret_cast<PFN_xrGetInstanceProcAddr>(
        pfnGetInstanceProcAddr))(instance, name, function);
  }

  //! @brief Call xrEnumerateApiLayerProperties, populating function pointer if
  //! required.
  XrResult xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                         uint32_t *propertyCountOutput,
                                         XrApiLayerProperties *properties) {

    XrResult result = populate_("xrEnumerateApiLayerProperties",
                                pfnEnumerateApiLayerProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateApiLayerProperties>(
        pfnEnumerateApiLayerProperties))(propertyCapacityInput,
                                         propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateApiLayerProperties (const overload - does not
  //! populate function pointer)
  XrResult
  xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                uint32_t *propertyCountOutput,
                                XrApiLayerProperties *properties) const {

    return (reinterpret_cast<PFN_xrEnumerateApiLayerProperties>(
        pfnEnumerateApiLayerProperties))(propertyCapacityInput,
                                         propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateInstanceExtensionProperties, populating function
  //! pointer if required.
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) {

    XrResult result = populate_("xrEnumerateInstanceExtensionProperties",
                                pfnEnumerateInstanceExtensionProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateInstanceExtensionProperties>(
        pfnEnumerateInstanceExtensionProperties))(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateInstanceExtensionProperties (const overload - does
  //! not populate function pointer)
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) const {

    return (reinterpret_cast<PFN_xrEnumerateInstanceExtensionProperties>(
        pfnEnumerateInstanceExtensionProperties))(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }

  //! @brief Call xrCreateInstance, populating function pointer if required.
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) {

    XrResult result = populate_("xrCreateInstance", pfnCreateInstance);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateInstance>(pfnCreateInstance))(
        createInfo, instance);
  }

  //! @brief Call xrCreateInstance (const overload - does not populate function
  //! pointer)
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) const {

    return (reinterpret_cast<PFN_xrCreateInstance>(pfnCreateInstance))(
        createInfo, instance);
  }

  //! @brief Call xrDestroyInstance, populating function pointer if required.
  XrResult xrDestroyInstance(XrInstance instance) {

    XrResult result = populate_("xrDestroyInstance", pfnDestroyInstance);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyInstance>(pfnDestroyInstance))(
        instance);
  }

  //! @brief Call xrDestroyInstance (const overload - does not populate function
  //! pointer)
  XrResult xrDestroyInstance(XrInstance instance) const {

    return (reinterpret_cast<PFN_xrDestroyInstance>(pfnDestroyInstance))(
        instance);
  }

  //! @brief Call xrGetInstanceProperties, populating function pointer if
  //! required.
  XrResult xrGetInstanceProperties(XrInstance instance,
                                   XrInstanceProperties *instanceProperties) {

    XrResult result =
        populate_("xrGetInstanceProperties", pfnGetInstanceProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInstanceProperties>(
        pfnGetInstanceProperties))(instance, instanceProperties);
  }

  //! @brief Call xrGetInstanceProperties (const overload - does not populate
  //! function pointer)
  XrResult
  xrGetInstanceProperties(XrInstance instance,
                          XrInstanceProperties *instanceProperties) const {

    return (reinterpret_cast<PFN_xrGetInstanceProperties>(
        pfnGetInstanceProperties))(instance, instanceProperties);
  }

  //! @brief Call xrPollEvent, populating function pointer if required.
  XrResult xrPollEvent(XrInstance instance, XrEventDataBuffer *eventData) {

    XrResult result = populate_("xrPollEvent", pfnPollEvent);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPollEvent>(pfnPollEvent))(instance,
                                                             eventData);
  }

  //! @brief Call xrPollEvent (const overload - does not populate function
  //! pointer)
  XrResult xrPollEvent(XrInstance instance,
                       XrEventDataBuffer *eventData) const {

    return (reinterpret_cast<PFN_xrPollEvent>(pfnPollEvent))(instance,
                                                             eventData);
  }

  //! @brief Call xrResultToString, populating function pointer if required.
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) {

    XrResult result = populate_("xrResultToString", pfnResultToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrResultToString>(pfnResultToString))(
        instance, value, buffer);
  }

  //! @brief Call xrResultToString (const overload - does not populate function
  //! pointer)
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) const {

    return (reinterpret_cast<PFN_xrResultToString>(pfnResultToString))(
        instance, value, buffer);
  }

  //! @brief Call xrStructureTypeToString, populating function pointer if
  //! required.
  XrResult xrStructureTypeToString(XrInstance instance, XrStructureType value,
                                   char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) {

    XrResult result =
        populate_("xrStructureTypeToString", pfnStructureTypeToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStructureTypeToString>(
        pfnStructureTypeToString))(instance, value, buffer);
  }

  //! @brief Call xrStructureTypeToString (const overload - does not populate
  //! function pointer)
  XrResult
  xrStructureTypeToString(XrInstance instance, XrStructureType value,
                          char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) const {

    return (reinterpret_cast<PFN_xrStructureTypeToString>(
        pfnStructureTypeToString))(instance, value, buffer);
  }

  //! @brief Call xrGetSystem, populating function pointer if required.
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) {

    XrResult result = populate_("xrGetSystem", pfnGetSystem);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetSystem>(pfnGetSystem))(instance, getInfo,
                                                             systemId);
  }

  //! @brief Call xrGetSystem (const overload - does not populate function
  //! pointer)
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) const {

    return (reinterpret_cast<PFN_xrGetSystem>(pfnGetSystem))(instance, getInfo,
                                                             systemId);
  }

  //! @brief Call xrGetSystemProperties, populating function pointer if
  //! required.
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) {

    XrResult result =
        populate_("xrGetSystemProperties", pfnGetSystemProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetSystemProperties>(
        pfnGetSystemProperties))(instance, systemId, properties);
  }

  //! @brief Call xrGetSystemProperties (const overload - does not populate
  //! function pointer)
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) const {

    return (reinterpret_cast<PFN_xrGetSystemProperties>(
        pfnGetSystemProperties))(instance, systemId, properties);
  }

  //! @brief Call xrEnumerateEnvironmentBlendModes, populating function pointer
  //! if required.
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) {

    XrResult result = populate_("xrEnumerateEnvironmentBlendModes",
                                pfnEnumerateEnvironmentBlendModes);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateEnvironmentBlendModes>(
        pfnEnumerateEnvironmentBlendModes))(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }

  //! @brief Call xrEnumerateEnvironmentBlendModes (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) const {

    return (reinterpret_cast<PFN_xrEnumerateEnvironmentBlendModes>(
        pfnEnumerateEnvironmentBlendModes))(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }

  //! @brief Call xrCreateSession, populating function pointer if required.
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) {

    XrResult result = populate_("xrCreateSession", pfnCreateSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSession>(pfnCreateSession))(
        instance, createInfo, session);
  }

  //! @brief Call xrCreateSession (const overload - does not populate function
  //! pointer)
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) const {

    return (reinterpret_cast<PFN_xrCreateSession>(pfnCreateSession))(
        instance, createInfo, session);
  }

  //! @brief Call xrDestroySession, populating function pointer if required.
  XrResult xrDestroySession(XrSession session) {

    XrResult result = populate_("xrDestroySession", pfnDestroySession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySession>(pfnDestroySession))(session);
  }

  //! @brief Call xrDestroySession (const overload - does not populate function
  //! pointer)
  XrResult xrDestroySession(XrSession session) const {

    return (reinterpret_cast<PFN_xrDestroySession>(pfnDestroySession))(session);
  }

  //! @brief Call xrEnumerateReferenceSpaces, populating function pointer if
  //! required.
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) {

    XrResult result =
        populate_("xrEnumerateReferenceSpaces", pfnEnumerateReferenceSpaces);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateReferenceSpaces>(
        pfnEnumerateReferenceSpaces))(session, spaceCapacityInput,
                                      spaceCountOutput, spaces);
  }

  //! @brief Call xrEnumerateReferenceSpaces (const overload - does not populate
  //! function pointer)
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) const {

    return (reinterpret_cast<PFN_xrEnumerateReferenceSpaces>(
        pfnEnumerateReferenceSpaces))(session, spaceCapacityInput,
                                      spaceCountOutput, spaces);
  }

  //! @brief Call xrCreateReferenceSpace, populating function pointer if
  //! required.
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) {

    XrResult result =
        populate_("xrCreateReferenceSpace", pfnCreateReferenceSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateReferenceSpace>(
        pfnCreateReferenceSpace))(session, createInfo, space);
  }

  //! @brief Call xrCreateReferenceSpace (const overload - does not populate
  //! function pointer)
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateReferenceSpace>(
        pfnCreateReferenceSpace))(session, createInfo, space);
  }

  //! @brief Call xrGetReferenceSpaceBoundsRect, populating function pointer if
  //! required.
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) {

    XrResult result = populate_("xrGetReferenceSpaceBoundsRect",
                                pfnGetReferenceSpaceBoundsRect);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetReferenceSpaceBoundsRect>(
        pfnGetReferenceSpaceBoundsRect))(session, referenceSpaceType, bounds);
  }

  //! @brief Call xrGetReferenceSpaceBoundsRect (const overload - does not
  //! populate function pointer)
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) const {

    return (reinterpret_cast<PFN_xrGetReferenceSpaceBoundsRect>(
        pfnGetReferenceSpaceBoundsRect))(session, referenceSpaceType, bounds);
  }

  //! @brief Call xrCreateActionSpace, populating function pointer if required.
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) {

    XrResult result = populate_("xrCreateActionSpace", pfnCreateActionSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateActionSpace>(pfnCreateActionSpace))(
        session, createInfo, space);
  }

  //! @brief Call xrCreateActionSpace (const overload - does not populate
  //! function pointer)
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateActionSpace>(pfnCreateActionSpace))(
        session, createInfo, space);
  }

  //! @brief Call xrLocateSpace, populating function pointer if required.
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) {

    XrResult result = populate_("xrLocateSpace", pfnLocateSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrLocateSpace>(pfnLocateSpace))(
        space, baseSpace, time, location);
  }

  //! @brief Call xrLocateSpace (const overload - does not populate function
  //! pointer)
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) const {

    return (reinterpret_cast<PFN_xrLocateSpace>(pfnLocateSpace))(
        space, baseSpace, time, location);
  }

  //! @brief Call xrDestroySpace, populating function pointer if required.
  XrResult xrDestroySpace(XrSpace space) {

    XrResult result = populate_("xrDestroySpace", pfnDestroySpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySpace>(pfnDestroySpace))(space);
  }

  //! @brief Call xrDestroySpace (const overload - does not populate function
  //! pointer)
  XrResult xrDestroySpace(XrSpace space) const {

    return (reinterpret_cast<PFN_xrDestroySpace>(pfnDestroySpace))(space);
  }

  //! @brief Call xrEnumerateViewConfigurations, populating function pointer if
  //! required.
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) {

    XrResult result = populate_("xrEnumerateViewConfigurations",
                                pfnEnumerateViewConfigurations);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurations>(
        pfnEnumerateViewConfigurations))(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }

  //! @brief Call xrEnumerateViewConfigurations (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) const {

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurations>(
        pfnEnumerateViewConfigurations))(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }

  //! @brief Call xrGetViewConfigurationProperties, populating function pointer
  //! if required.
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) {

    XrResult result = populate_("xrGetViewConfigurationProperties",
                                pfnGetViewConfigurationProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetViewConfigurationProperties>(
        pfnGetViewConfigurationProperties))(
        instance, systemId, viewConfigurationType, configurationProperties);
  }

  //! @brief Call xrGetViewConfigurationProperties (const overload - does not
  //! populate function pointer)
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) const {

    return (reinterpret_cast<PFN_xrGetViewConfigurationProperties>(
        pfnGetViewConfigurationProperties))(
        instance, systemId, viewConfigurationType, configurationProperties);
  }

  //! @brief Call xrEnumerateViewConfigurationViews, populating function pointer
  //! if required.
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) {

    XrResult result = populate_("xrEnumerateViewConfigurationViews",
                                pfnEnumerateViewConfigurationViews);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurationViews>(
        pfnEnumerateViewConfigurationViews))(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }

  //! @brief Call xrEnumerateViewConfigurationViews (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) const {

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurationViews>(
        pfnEnumerateViewConfigurationViews))(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }

  //! @brief Call xrEnumerateSwapchainFormats, populating function pointer if
  //! required.
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) {

    XrResult result =
        populate_("xrEnumerateSwapchainFormats", pfnEnumerateSwapchainFormats);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateSwapchainFormats>(
        pfnEnumerateSwapchainFormats))(session, formatCapacityInput,
                                       formatCountOutput, formats);
  }

  //! @brief Call xrEnumerateSwapchainFormats (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) const {

    return (reinterpret_cast<PFN_xrEnumerateSwapchainFormats>(
        pfnEnumerateSwapchainFormats))(session, formatCapacityInput,
                                       formatCountOutput, formats);
  }

  //! @brief Call xrCreateSwapchain, populating function pointer if required.
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) {

    XrResult result = populate_("xrCreateSwapchain", pfnCreateSwapchain);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSwapchain>(pfnCreateSwapchain))(
        session, createInfo, swapchain);
  }

  //! @brief Call xrCreateSwapchain (const overload - does not populate function
  //! pointer)
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) const {

    return (reinterpret_cast<PFN_xrCreateSwapchain>(pfnCreateSwapchain))(
        session, createInfo, swapchain);
  }

  //! @brief Call xrDestroySwapchain, populating function pointer if required.
  XrResult xrDestroySwapchain(XrSwapchain swapchain) {

    XrResult result = populate_("xrDestroySwapchain", pfnDestroySwapchain);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySwapchain>(pfnDestroySwapchain))(
        swapchain);
  }

  //! @brief Call xrDestroySwapchain (const overload - does not populate
  //! function pointer)
  XrResult xrDestroySwapchain(XrSwapchain swapchain) const {

    return (reinterpret_cast<PFN_xrDestroySwapchain>(pfnDestroySwapchain))(
        swapchain);
  }

  //! @brief Call xrEnumerateSwapchainImages, populating function pointer if
  //! required.
  XrResult xrEnumerateSwapchainImages(XrSwapchain swapchain,
                                      uint32_t imageCapacityInput,
                                      uint32_t *imageCountOutput,
                                      XrSwapchainImageBaseHeader *images) {

    XrResult result =
        populate_("xrEnumerateSwapchainImages", pfnEnumerateSwapchainImages);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateSwapchainImages>(
        pfnEnumerateSwapchainImages))(swapchain, imageCapacityInput,
                                      imageCountOutput, images);
  }

  //! @brief Call xrEnumerateSwapchainImages (const overload - does not populate
  //! function pointer)
  XrResult
  xrEnumerateSwapchainImages(XrSwapchain swapchain, uint32_t imageCapacityInput,
                             uint32_t *imageCountOutput,
                             XrSwapchainImageBaseHeader *images) const {

    return (reinterpret_cast<PFN_xrEnumerateSwapchainImages>(
        pfnEnumerateSwapchainImages))(swapchain, imageCapacityInput,
                                      imageCountOutput, images);
  }

  //! @brief Call xrAcquireSwapchainImage, populating function pointer if
  //! required.
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) {

    XrResult result =
        populate_("xrAcquireSwapchainImage", pfnAcquireSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrAcquireSwapchainImage>(
        pfnAcquireSwapchainImage))(swapchain, acquireInfo, index);
  }

  //! @brief Call xrAcquireSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) const {

    return (reinterpret_cast<PFN_xrAcquireSwapchainImage>(
        pfnAcquireSwapchainImage))(swapchain, acquireInfo, index);
  }

  //! @brief Call xrWaitSwapchainImage, populating function pointer if required.
  XrResult xrWaitSwapchainImage(XrSwapchain swapchain,
                                const XrSwapchainImageWaitInfo *waitInfo) {

    XrResult result = populate_("xrWaitSwapchainImage", pfnWaitSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrWaitSwapchainImage>(pfnWaitSwapchainImage))(
        swapchain, waitInfo);
  }

  //! @brief Call xrWaitSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult
  xrWaitSwapchainImage(XrSwapchain swapchain,
                       const XrSwapchainImageWaitInfo *waitInfo) const {

    return (reinterpret_cast<PFN_xrWaitSwapchainImage>(pfnWaitSwapchainImage))(
        swapchain, waitInfo);
  }

  //! @brief Call xrReleaseSwapchainImage, populating function pointer if
  //! required.
  XrResult
  xrReleaseSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageReleaseInfo *releaseInfo) {

    XrResult result =
        populate_("xrReleaseSwapchainImage", pfnReleaseSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrReleaseSwapchainImage>(
        pfnReleaseSwapchainImage))(swapchain, releaseInfo);
  }

  //! @brief Call xrReleaseSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult xrReleaseSwapchainImage(
      XrSwapchain swapchain,
      const XrSwapchainImageReleaseInfo *releaseInfo) const {

    return (reinterpret_cast<PFN_xrReleaseSwapchainImage>(
        pfnReleaseSwapchainImage))(swapchain, releaseInfo);
  }

  //! @brief Call xrBeginSession, populating function pointer if required.
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) {

    XrResult result = populate_("xrBeginSession", pfnBeginSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrBeginSession>(pfnBeginSession))(session,
                                                                   beginInfo);
  }

  //! @brief Call xrBeginSession (const overload - does not populate function
  //! pointer)
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) const {

    return (reinterpret_cast<PFN_xrBeginSession>(pfnBeginSession))(session,
                                                                   beginInfo);
  }

  //! @brief Call xrEndSession, populating function pointer if required.
  XrResult xrEndSession(XrSession session) {

    XrResult result = populate_("xrEndSession", pfnEndSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEndSession>(pfnEndSession))(session);
  }

  //! @brief Call xrEndSession (const overload - does not populate function
  //! pointer)
  XrResult xrEndSession(XrSession session) const {

    return (reinterpret_cast<PFN_xrEndSession>(pfnEndSession))(session);
  }

  //! @brief Call xrRequestExitSession, populating function pointer if required.
  XrResult xrRequestExitSession(XrSession session) {

    XrResult result = populate_("xrRequestExitSession", pfnRequestExitSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrRequestExitSession>(pfnRequestExitSession))(
        session);
  }

  //! @brief Call xrRequestExitSession (const overload - does not populate
  //! function pointer)
  XrResult xrRequestExitSession(XrSession session) const {

    return (reinterpret_cast<PFN_xrRequestExitSession>(pfnRequestExitSession))(
        session);
  }

  //! @brief Call xrWaitFrame, populating function pointer if required.
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) {

    XrResult result = populate_("xrWaitFrame", pfnWaitFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrWaitFrame>(pfnWaitFrame))(
        session, frameWaitInfo, frameState);
  }

  //! @brief Call xrWaitFrame (const overload - does not populate function
  //! pointer)
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) const {

    return (reinterpret_cast<PFN_xrWaitFrame>(pfnWaitFrame))(
        session, frameWaitInfo, frameState);
  }

  //! @brief Call xrBeginFrame, populating function pointer if required.
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) {

    XrResult result = populate_("xrBeginFrame", pfnBeginFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrBeginFrame>(pfnBeginFrame))(session,
                                                               frameBeginInfo);
  }

  //! @brief Call xrBeginFrame (const overload - does not populate function
  //! pointer)
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) const {

    return (reinterpret_cast<PFN_xrBeginFrame>(pfnBeginFrame))(session,
                                                               frameBeginInfo);
  }

  //! @brief Call xrEndFrame, populating function pointer if required.
  XrResult xrEndFrame(XrSession session, const XrFrameEndInfo *frameEndInfo) {

    XrResult result = populate_("xrEndFrame", pfnEndFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEndFrame>(pfnEndFrame))(session,
                                                           frameEndInfo);
  }

  //! @brief Call xrEndFrame (const overload - does not populate function
  //! pointer)
  XrResult xrEndFrame(XrSession session,
                      const XrFrameEndInfo *frameEndInfo) const {

    return (reinterpret_cast<PFN_xrEndFrame>(pfnEndFrame))(session,
                                                           frameEndInfo);
  }

  //! @brief Call xrLocateViews, populating function pointer if required.
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) {

    XrResult result = populate_("xrLocateViews", pfnLocateViews);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrLocateViews>(pfnLocateViews))(
        session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput,
        views);
  }

  //! @brief Call xrLocateViews (const overload - does not populate function
  //! pointer)
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) const {

    return (reinterpret_cast<PFN_xrLocateViews>(pfnLocateViews))(
        session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput,
        views);
  }

  //! @brief Call xrStringToPath, populating function pointer if required.
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) {

    XrResult result = populate_("xrStringToPath", pfnStringToPath);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStringToPath>(pfnStringToPath))(
        instance, pathString, path);
  }

  //! @brief Call xrStringToPath (const overload - does not populate function
  //! pointer)
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) const {

    return (reinterpret_cast<PFN_xrStringToPath>(pfnStringToPath))(
        instance, pathString, path);
  }

  //! @brief Call xrPathToString, populating function pointer if required.
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) {

    XrResult result = populate_("xrPathToString", pfnPathToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPathToString>(pfnPathToString))(
        instance, path, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrPathToString (const overload - does not populate function
  //! pointer)
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) const {

    return (reinterpret_cast<PFN_xrPathToString>(pfnPathToString))(
        instance, path, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrCreateActionSet, populating function pointer if required.
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) {

    XrResult result = populate_("xrCreateActionSet", pfnCreateActionSet);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateActionSet>(pfnCreateActionSet))(
        instance, createInfo, actionSet);
  }

  //! @brief Call xrCreateActionSet (const overload - does not populate function
  //! pointer)
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) const {

    return (reinterpret_cast<PFN_xrCreateActionSet>(pfnCreateActionSet))(
        instance, createInfo, actionSet);
  }

  //! @brief Call xrDestroyActionSet, populating function pointer if required.
  XrResult xrDestroyActionSet(XrActionSet actionSet) {

    XrResult result = populate_("xrDestroyActionSet", pfnDestroyActionSet);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyActionSet>(pfnDestroyActionSet))(
        actionSet);
  }

  //! @brief Call xrDestroyActionSet (const overload - does not populate
  //! function pointer)
  XrResult xrDestroyActionSet(XrActionSet actionSet) const {

    return (reinterpret_cast<PFN_xrDestroyActionSet>(pfnDestroyActionSet))(
        actionSet);
  }

  //! @brief Call xrCreateAction, populating function pointer if required.
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) {

    XrResult result = populate_("xrCreateAction", pfnCreateAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateAction>(pfnCreateAction))(
        actionSet, createInfo, action);
  }

  //! @brief Call xrCreateAction (const overload - does not populate function
  //! pointer)
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) const {

    return (reinterpret_cast<PFN_xrCreateAction>(pfnCreateAction))(
        actionSet, createInfo, action);
  }

  //! @brief Call xrDestroyAction, populating function pointer if required.
  XrResult xrDestroyAction(XrAction action) {

    XrResult result = populate_("xrDestroyAction", pfnDestroyAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyAction>(pfnDestroyAction))(action);
  }

  //! @brief Call xrDestroyAction (const overload - does not populate function
  //! pointer)
  XrResult xrDestroyAction(XrAction action) const {

    return (reinterpret_cast<PFN_xrDestroyAction>(pfnDestroyAction))(action);
  }

  //! @brief Call xrSuggestInteractionProfileBindings, populating function
  //! pointer if required.
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) {

    XrResult result = populate_("xrSuggestInteractionProfileBindings",
                                pfnSuggestInteractionProfileBindings);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSuggestInteractionProfileBindings>(
        pfnSuggestInteractionProfileBindings))(instance, suggestedBindings);
  }

  //! @brief Call xrSuggestInteractionProfileBindings (const overload - does not
  //! populate function pointer)
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) const {

    return (reinterpret_cast<PFN_xrSuggestInteractionProfileBindings>(
        pfnSuggestInteractionProfileBindings))(instance, suggestedBindings);
  }

  //! @brief Call xrAttachSessionActionSets, populating function pointer if
  //! required.
  XrResult
  xrAttachSessionActionSets(XrSession session,
                            const XrSessionActionSetsAttachInfo *attachInfo) {

    XrResult result =
        populate_("xrAttachSessionActionSets", pfnAttachSessionActionSets);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrAttachSessionActionSets>(
        pfnAttachSessionActionSets))(session, attachInfo);
  }

  //! @brief Call xrAttachSessionActionSets (const overload - does not populate
  //! function pointer)
  XrResult xrAttachSessionActionSets(
      XrSession session,
      const XrSessionActionSetsAttachInfo *attachInfo) const {

    return (reinterpret_cast<PFN_xrAttachSessionActionSets>(
        pfnAttachSessionActionSets))(session, attachInfo);
  }

  //! @brief Call xrGetCurrentInteractionProfile, populating function pointer if
  //! required.
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) {

    XrResult result = populate_("xrGetCurrentInteractionProfile",
                                pfnGetCurrentInteractionProfile);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetCurrentInteractionProfile>(
        pfnGetCurrentInteractionProfile))(session, topLevelUserPath,
                                          interactionProfile);
  }

  //! @brief Call xrGetCurrentInteractionProfile (const overload - does not
  //! populate function pointer)
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) const {

    return (reinterpret_cast<PFN_xrGetCurrentInteractionProfile>(
        pfnGetCurrentInteractionProfile))(session, topLevelUserPath,
                                          interactionProfile);
  }

  //! @brief Call xrGetActionStateBoolean, populating function pointer if
  //! required.
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) {

    XrResult result =
        populate_("xrGetActionStateBoolean", pfnGetActionStateBoolean);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateBoolean>(
        pfnGetActionStateBoolean))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateBoolean (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateBoolean>(
        pfnGetActionStateBoolean))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateFloat, populating function pointer if
  //! required.
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) {

    XrResult result =
        populate_("xrGetActionStateFloat", pfnGetActionStateFloat);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateFloat>(
        pfnGetActionStateFloat))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateFloat (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateFloat>(
        pfnGetActionStateFloat))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateVector2f, populating function pointer if
  //! required.
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) {

    XrResult result =
        populate_("xrGetActionStateVector2f", pfnGetActionStateVector2f);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateVector2f>(
        pfnGetActionStateVector2f))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateVector2f (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateVector2f>(
        pfnGetActionStateVector2f))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStatePose, populating function pointer if required.
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) {

    XrResult result = populate_("xrGetActionStatePose", pfnGetActionStatePose);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStatePose>(pfnGetActionStatePose))(
        session, getInfo, state);
  }

  //! @brief Call xrGetActionStatePose (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) const {

    return (reinterpret_cast<PFN_xrGetActionStatePose>(pfnGetActionStatePose))(
        session, getInfo, state);
  }

  //! @brief Call xrSyncActions, populating function pointer if required.
  XrResult xrSyncActions(XrSession session, const XrActionsSyncInfo *syncInfo) {

    XrResult result = populate_("xrSyncActions", pfnSyncActions);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSyncActions>(pfnSyncActions))(session,
                                                                 syncInfo);
  }

  //! @brief Call xrSyncActions (const overload - does not populate function
  //! pointer)
  XrResult xrSyncActions(XrSession session,
                         const XrActionsSyncInfo *syncInfo) const {

    return (reinterpret_cast<PFN_xrSyncActions>(pfnSyncActions))(session,
                                                                 syncInfo);
  }

  //! @brief Call xrEnumerateBoundSourcesForAction, populating function pointer
  //! if required.
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) {

    XrResult result = populate_("xrEnumerateBoundSourcesForAction",
                                pfnEnumerateBoundSourcesForAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateBoundSourcesForAction>(
        pfnEnumerateBoundSourcesForAction))(session, enumerateInfo,
                                            sourceCapacityInput,
                                            sourceCountOutput, sources);
  }

  //! @brief Call xrEnumerateBoundSourcesForAction (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) const {

    return (reinterpret_cast<PFN_xrEnumerateBoundSourcesForAction>(
        pfnEnumerateBoundSourcesForAction))(session, enumerateInfo,
                                            sourceCapacityInput,
                                            sourceCountOutput, sources);
  }

  //! @brief Call xrGetInputSourceLocalizedName, populating function pointer if
  //! required.
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput, char *buffer) {

    XrResult result = populate_("xrGetInputSourceLocalizedName",
                                pfnGetInputSourceLocalizedName);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInputSourceLocalizedName>(
        pfnGetInputSourceLocalizedName))(session, getInfo, bufferCapacityInput,
                                         bufferCountOutput, buffer);
  }

  //! @brief Call xrGetInputSourceLocalizedName (const overload - does not
  //! populate function pointer)
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput,
      char *buffer) const {

    return (reinterpret_cast<PFN_xrGetInputSourceLocalizedName>(
        pfnGetInputSourceLocalizedName))(session, getInfo, bufferCapacityInput,
                                         bufferCountOutput, buffer);
  }

  //! @brief Call xrApplyHapticFeedback, populating function pointer if
  //! required.
  XrResult xrApplyHapticFeedback(XrSession session,
                                 const XrHapticActionInfo *hapticActionInfo,
                                 const XrHapticBaseHeader *hapticFeedback) {

    XrResult result =
        populate_("xrApplyHapticFeedback", pfnApplyHapticFeedback);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrApplyHapticFeedback>(
        pfnApplyHapticFeedback))(session, hapticActionInfo, hapticFeedback);
  }

  //! @brief Call xrApplyHapticFeedback (const overload - does not populate
  //! function pointer)
  XrResult
  xrApplyHapticFeedback(XrSession session,
                        const XrHapticActionInfo *hapticActionInfo,
                        const XrHapticBaseHeader *hapticFeedback) const {

    return (reinterpret_cast<PFN_xrApplyHapticFeedback>(
        pfnApplyHapticFeedback))(session, hapticActionInfo, hapticFeedback);
  }

  //! @brief Call xrStopHapticFeedback, populating function pointer if required.
  XrResult xrStopHapticFeedback(XrSession session,
                                const XrHapticActionInfo *hapticActionInfo) {

    XrResult result = populate_("xrStopHapticFeedback", pfnStopHapticFeedback);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStopHapticFeedback>(pfnStopHapticFeedback))(
        session, hapticActionInfo);
  }

  //! @brief Call xrStopHapticFeedback (const overload - does not populate
  //! function pointer)
  XrResult
  xrStopHapticFeedback(XrSession session,
                       const XrHapticActionInfo *hapticActionInfo) const {

    return (reinterpret_cast<PFN_xrStopHapticFeedback>(pfnStopHapticFeedback))(
        session, hapticActionInfo);
  }

#if defined(XR_USE_PLATFORM_ANDROID)
  //! @brief Call xrSetAndroidApplicationThreadKHR, populating function pointer
  //! if required.
  XrResult xrSetAndroidApplicationThreadKHR(XrSession session,
                                            XrAndroidThreadTypeKHR threadType,
                                            uint32_t threadId) {

    XrResult result = populate_("xrSetAndroidApplicationThreadKHR",
                                pfnSetAndroidApplicationThreadKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSetAndroidApplicationThreadKHR>(
        pfnSetAndroidApplicationThreadKHR))(session, threadType, threadId);
  }

  //! @brief Call xrSetAndroidApplicationThreadKHR (const overload - does not
  //! populate function pointer)
  XrResult xrSetAndroidApplicationThreadKHR(XrSession session,
                                            XrAndroidThreadTypeKHR threadType,
                                            uint32_t threadId) const {

    return (reinterpret_cast<PFN_xrSetAndroidApplicationThreadKHR>(
        pfnSetAndroidApplicationThreadKHR))(session, threadType, threadId);
  }
#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)
  //! @brief Call xrCreateSwapchainAndroidSurfaceKHR, populating function
  //! pointer if required.
  XrResult xrCreateSwapchainAndroidSurfaceKHR(XrSession session,
                                              const XrSwapchainCreateInfo *info,
                                              XrSwapchain *swapchain,
                                              jobject *surface) {

    XrResult result = populate_("xrCreateSwapchainAndroidSurfaceKHR",
                                pfnCreateSwapchainAndroidSurfaceKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSwapchainAndroidSurfaceKHR>(
        pfnCreateSwapchainAndroidSurfaceKHR))(session, info, swapchain,
                                              surface);
  }

  //! @brief Call xrCreateSwapchainAndroidSurfaceKHR (const overload - does not
  //! populate function pointer)
  XrResult xrCreateSwapchainAndroidSurfaceKHR(XrSession session,
                                              const XrSwapchainCreateInfo *info,
                                              XrSwapchain *swapchain,
                                              jobject *surface) const {

    return (reinterpret_cast<PFN_xrCreateSwapchainAndroidSurfaceKHR>(
        pfnCreateSwapchainAndroidSurfaceKHR))(session, info, swapchain,
                                              surface);
  }
#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_GRAPHICS_API_OPENGL)
  //! @brief Call xrGetOpenGLGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetOpenGLGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetOpenGLGraphicsRequirementsKHR",
                                pfnGetOpenGLGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetOpenGLGraphicsRequirementsKHR>(
        pfnGetOpenGLGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }

  //! @brief Call xrGetOpenGLGraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetOpenGLGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetOpenGLGraphicsRequirementsKHR>(
        pfnGetOpenGLGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
  //! @brief Call xrGetOpenGLESGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetOpenGLESGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetOpenGLESGraphicsRequirementsKHR",
                                pfnGetOpenGLESGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetOpenGLESGraphicsRequirementsKHR>(
        pfnGetOpenGLESGraphicsRequirementsKHR))(instance, systemId,
                                                graphicsRequirements);
  }

  //! @brief Call xrGetOpenGLESGraphicsRequirementsKHR (const overload - does
  //! not populate function pointer)
  XrResult xrGetOpenGLESGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetOpenGLESGraphicsRequirementsKHR>(
        pfnGetOpenGLESGraphicsRequirementsKHR))(instance, systemId,
                                                graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanInstanceExtensionsKHR, populating function pointer
  //! if required.
  XrResult xrGetVulkanInstanceExtensionsKHR(XrInstance instance,
                                            XrSystemId systemId,
                                            uint32_t bufferCapacityInput,
                                            uint32_t *bufferCountOutput,
                                            char *buffer) {

    XrResult result = populate_("xrGetVulkanInstanceExtensionsKHR",
                                pfnGetVulkanInstanceExtensionsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanInstanceExtensionsKHR>(
        pfnGetVulkanInstanceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrGetVulkanInstanceExtensionsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanInstanceExtensionsKHR(XrInstance instance,
                                            XrSystemId systemId,
                                            uint32_t bufferCapacityInput,
                                            uint32_t *bufferCountOutput,
                                            char *buffer) const {

    return (reinterpret_cast<PFN_xrGetVulkanInstanceExtensionsKHR>(
        pfnGetVulkanInstanceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanDeviceExtensionsKHR, populating function pointer if
  //! required.
  XrResult xrGetVulkanDeviceExtensionsKHR(XrInstance instance,
                                          XrSystemId systemId,
                                          uint32_t bufferCapacityInput,
                                          uint32_t *bufferCountOutput,
                                          char *buffer) {

    XrResult result = populate_("xrGetVulkanDeviceExtensionsKHR",
                                pfnGetVulkanDeviceExtensionsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanDeviceExtensionsKHR>(
        pfnGetVulkanDeviceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrGetVulkanDeviceExtensionsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanDeviceExtensionsKHR(XrInstance instance,
                                          XrSystemId systemId,
                                          uint32_t bufferCapacityInput,
                                          uint32_t *bufferCountOutput,
                                          char *buffer) const {

    return (reinterpret_cast<PFN_xrGetVulkanDeviceExtensionsKHR>(
        pfnGetVulkanDeviceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanGraphicsDeviceKHR, populating function pointer if
  //! required.
  XrResult xrGetVulkanGraphicsDeviceKHR(XrInstance instance,
                                        XrSystemId systemId,
                                        VkInstance vkInstance,
                                        VkPhysicalDevice *vkPhysicalDevice) {

    XrResult result = populate_("xrGetVulkanGraphicsDeviceKHR",
                                pfnGetVulkanGraphicsDeviceKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsDeviceKHR>(
        pfnGetVulkanGraphicsDeviceKHR))(instance, systemId, vkInstance,
                                        vkPhysicalDevice);
  }

  //! @brief Call xrGetVulkanGraphicsDeviceKHR (const overload - does not
  //! populate function pointer)
  XrResult
  xrGetVulkanGraphicsDeviceKHR(XrInstance instance, XrSystemId systemId,
                               VkInstance vkInstance,
                               VkPhysicalDevice *vkPhysicalDevice) const {

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsDeviceKHR>(
        pfnGetVulkanGraphicsDeviceKHR))(instance, systemId, vkInstance,
                                        vkPhysicalDevice);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetVulkanGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetVulkanGraphicsRequirementsKHR",
                                pfnGetVulkanGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsRequirementsKHR>(
        pfnGetVulkanGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }

  //! @brief Call xrGetVulkanGraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsRequirementsKHR>(
        pfnGetVulkanGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)
  //! @brief Call xrGetD3D11GraphicsRequirementsKHR, populating function pointer
  //! if required.
  XrResult xrGetD3D11GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D11KHR *graphicsRequirements) {

    XrResult result = populate_("xrGetD3D11GraphicsRequirementsKHR",
                                pfnGetD3D11GraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetD3D11GraphicsRequirementsKHR>(
        pfnGetD3D11GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }

  //! @brief Call xrGetD3D11GraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetD3D11GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D11KHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetD3D11GraphicsRequirementsKHR>(
        pfnGetD3D11GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)
  //! @brief Call xrGetD3D12GraphicsRequirementsKHR, populating function pointer
  //! if required.
  XrResult xrGetD3D12GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D12KHR *graphicsRequirements) {

    XrResult result = populate_("xrGetD3D12GraphicsRequirementsKHR",
                                pfnGetD3D12GraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetD3D12GraphicsRequirementsKHR>(
        pfnGetD3D12GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }

  //! @brief Call xrGetD3D12GraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetD3D12GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D12KHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetD3D12GraphicsRequirementsKHR>(
        pfnGetD3D12GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_D3D12)

  //! @brief Call xrGetVisibilityMaskKHR, populating function pointer if
  //! required.
  XrResult xrGetVisibilityMaskKHR(XrSession session,
                                  XrViewConfigurationType viewConfigurationType,
                                  uint32_t viewIndex,
                                  XrVisibilityMaskTypeKHR visibilityMaskType,
                                  XrVisibilityMaskKHR *visibilityMask) {

    XrResult result =
        populate_("xrGetVisibilityMaskKHR", pfnGetVisibilityMaskKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVisibilityMaskKHR>(
        pfnGetVisibilityMaskKHR))(session, viewConfigurationType, viewIndex,
                                  visibilityMaskType, visibilityMask);
  }

  //! @brief Call xrGetVisibilityMaskKHR (const overload - does not populate
  //! function pointer)
  XrResult xrGetVisibilityMaskKHR(XrSession session,
                                  XrViewConfigurationType viewConfigurationType,
                                  uint32_t viewIndex,
                                  XrVisibilityMaskTypeKHR visibilityMaskType,
                                  XrVisibilityMaskKHR *visibilityMask) const {

    return (reinterpret_cast<PFN_xrGetVisibilityMaskKHR>(
        pfnGetVisibilityMaskKHR))(session, viewConfigurationType, viewIndex,
                                  visibilityMaskType, visibilityMask);
  }

#if defined(XR_USE_PLATFORM_WIN32)
  //! @brief Call xrConvertWin32PerformanceCounterToTimeKHR, populating function
  //! pointer if required.
  XrResult xrConvertWin32PerformanceCounterToTimeKHR(
      XrInstance instance, const LARGE_INTEGER *performanceCounter,
      XrTime *time) {

    XrResult result = populate_("xrConvertWin32PerformanceCounterToTimeKHR",
                                pfnConvertWin32PerformanceCounterToTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertWin32PerformanceCounterToTimeKHR>(
        pfnConvertWin32PerformanceCounterToTimeKHR))(instance,
                                                     performanceCounter, time);
  }

  //! @brief Call xrConvertWin32PerformanceCounterToTimeKHR (const overload -
  //! does not populate function pointer)
  XrResult xrConvertWin32PerformanceCounterToTimeKHR(
      XrInstance instance, const LARGE_INTEGER *performanceCounter,
      XrTime *time) const {

    return (reinterpret_cast<PFN_xrConvertWin32PerformanceCounterToTimeKHR>(
        pfnConvertWin32PerformanceCounterToTimeKHR))(instance,
                                                     performanceCounter, time);
  }
#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)
  //! @brief Call xrConvertTimeToWin32PerformanceCounterKHR, populating function
  //! pointer if required.
  XrResult
  xrConvertTimeToWin32PerformanceCounterKHR(XrInstance instance, XrTime time,
                                            LARGE_INTEGER *performanceCounter) {

    XrResult result = populate_("xrConvertTimeToWin32PerformanceCounterKHR",
                                pfnConvertTimeToWin32PerformanceCounterKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimeToWin32PerformanceCounterKHR>(
        pfnConvertTimeToWin32PerformanceCounterKHR))(instance, time,
                                                     performanceCounter);
  }

  //! @brief Call xrConvertTimeToWin32PerformanceCounterKHR (const overload -
  //! does not populate function pointer)
  XrResult xrConvertTimeToWin32PerformanceCounterKHR(
      XrInstance instance, XrTime time,
      LARGE_INTEGER *performanceCounter) const {

    return (reinterpret_cast<PFN_xrConvertTimeToWin32PerformanceCounterKHR>(
        pfnConvertTimeToWin32PerformanceCounterKHR))(instance, time,
                                                     performanceCounter);
  }
#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)
  //! @brief Call xrConvertTimespecTimeToTimeKHR, populating function pointer if
  //! required.
  XrResult xrConvertTimespecTimeToTimeKHR(XrInstance instance,
                                          const struct timespec *timespecTime,
                                          XrTime *time) {

    XrResult result = populate_("xrConvertTimespecTimeToTimeKHR",
                                pfnConvertTimespecTimeToTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimespecTimeToTimeKHR>(
        pfnConvertTimespecTimeToTimeKHR))(instance, timespecTime, time);
  }

  //! @brief Call xrConvertTimespecTimeToTimeKHR (const overload - does not
  //! populate function pointer)
  XrResult xrConvertTimespecTimeToTimeKHR(XrInstance instance,
                                          const struct timespec *timespecTime,
                                          XrTime *time) const {

    return (reinterpret_cast<PFN_xrConvertTimespecTimeToTimeKHR>(
        pfnConvertTimespecTimeToTimeKHR))(instance, timespecTime, time);
  }
#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)
  //! @brief Call xrConvertTimeToTimespecTimeKHR, populating function pointer if
  //! required.
  XrResult xrConvertTimeToTimespecTimeKHR(XrInstance instance, XrTime time,
                                          struct timespec *timespecTime) {

    XrResult result = populate_("xrConvertTimeToTimespecTimeKHR",
                                pfnConvertTimeToTimespecTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimeToTimespecTimeKHR>(
        pfnConvertTimeToTimespecTimeKHR))(instance, time, timespecTime);
  }

  //! @brief Call xrConvertTimeToTimespecTimeKHR (const overload - does not
  //! populate function pointer)
  XrResult xrConvertTimeToTimespecTimeKHR(XrInstance instance, XrTime time,
                                          struct timespec *timespecTime) const {

    return (reinterpret_cast<PFN_xrConvertTimeToTimespecTimeKHR>(
        pfnConvertTimeToTimespecTimeKHR))(instance, time, timespecTime);
  }
#endif // defined(XR_USE_TIMESPEC)

  //! @brief Call xrPerfSettingsSetPerformanceLevelEXT, populating function
  //! pointer if required.
  XrResult xrPerfSettingsSetPerformanceLevelEXT(XrSession session,
                                                XrPerfSettingsDomainEXT domain,
                                                XrPerfSettingsLevelEXT level) {

    XrResult result = populate_("xrPerfSettingsSetPerformanceLevelEXT",
                                pfnPerfSettingsSetPerformanceLevelEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPerfSettingsSetPerformanceLevelEXT>(
        pfnPerfSettingsSetPerformanceLevelEXT))(session, domain, level);
  }

  //! @brief Call xrPerfSettingsSetPerformanceLevelEXT (const overload - does
  //! not populate function pointer)
  XrResult
  xrPerfSettingsSetPerformanceLevelEXT(XrSession session,
                                       XrPerfSettingsDomainEXT domain,
                                       XrPerfSettingsLevelEXT level) const {

    return (reinterpret_cast<PFN_xrPerfSettingsSetPerformanceLevelEXT>(
        pfnPerfSettingsSetPerformanceLevelEXT))(session, domain, level);
  }

  //! @brief Call xrThermalGetTemperatureTrendEXT, populating function pointer
  //! if required.
  XrResult xrThermalGetTemperatureTrendEXT(
      XrSession session, XrPerfSettingsDomainEXT domain,
      XrPerfSettingsNotificationLevelEXT *notificationLevel,
      float *tempHeadroom, float *tempSlope) {

    XrResult result = populate_("xrThermalGetTemperatureTrendEXT",
                                pfnThermalGetTemperatureTrendEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrThermalGetTemperatureTrendEXT>(
        pfnThermalGetTemperatureTrendEXT))(session, domain, notificationLevel,
                                           tempHeadroom, tempSlope);
  }

  //! @brief Call xrThermalGetTemperatureTrendEXT (const overload - does not
  //! populate function pointer)
  XrResult xrThermalGetTemperatureTrendEXT(
      XrSession session, XrPerfSettingsDomainEXT domain,
      XrPerfSettingsNotificationLevelEXT *notificationLevel,
      float *tempHeadroom, float *tempSlope) const {

    return (reinterpret_cast<PFN_xrThermalGetTemperatureTrendEXT>(
        pfnThermalGetTemperatureTrendEXT))(session, domain, notificationLevel,
                                           tempHeadroom, tempSlope);
  }

  //! @brief Call xrSetDebugUtilsObjectNameEXT, populating function pointer if
  //! required.
  XrResult
  xrSetDebugUtilsObjectNameEXT(XrInstance instance,
                               const XrDebugUtilsObjectNameInfoEXT *nameInfo) {

    XrResult result = populate_("xrSetDebugUtilsObjectNameEXT",
                                pfnSetDebugUtilsObjectNameEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSetDebugUtilsObjectNameEXT>(
        pfnSetDebugUtilsObjectNameEXT))(instance, nameInfo);
  }

  //! @brief Call xrSetDebugUtilsObjectNameEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSetDebugUtilsObjectNameEXT(
      XrInstance instance,
      const XrDebugUtilsObjectNameInfoEXT *nameInfo) const {

    return (reinterpret_cast<PFN_xrSetDebugUtilsObjectNameEXT>(
        pfnSetDebugUtilsObjectNameEXT))(instance, nameInfo);
  }

  //! @brief Call xrCreateDebugUtilsMessengerEXT, populating function pointer if
  //! required.
  XrResult xrCreateDebugUtilsMessengerEXT(
      XrInstance instance, const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
      XrDebugUtilsMessengerEXT *messenger) {

    XrResult result = populate_("xrCreateDebugUtilsMessengerEXT",
                                pfnCreateDebugUtilsMessengerEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateDebugUtilsMessengerEXT>(
        pfnCreateDebugUtilsMessengerEXT))(instance, createInfo, messenger);
  }

  //! @brief Call xrCreateDebugUtilsMessengerEXT (const overload - does not
  //! populate function pointer)
  XrResult xrCreateDebugUtilsMessengerEXT(
      XrInstance instance, const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
      XrDebugUtilsMessengerEXT *messenger) const {

    return (reinterpret_cast<PFN_xrCreateDebugUtilsMessengerEXT>(
        pfnCreateDebugUtilsMessengerEXT))(instance, createInfo, messenger);
  }

  //! @brief Call xrDestroyDebugUtilsMessengerEXT, populating function pointer
  //! if required.
  XrResult xrDestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT messenger) {

    XrResult result = populate_("xrDestroyDebugUtilsMessengerEXT",
                                pfnDestroyDebugUtilsMessengerEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyDebugUtilsMessengerEXT>(
        pfnDestroyDebugUtilsMessengerEXT))(messenger);
  }

  //! @brief Call xrDestroyDebugUtilsMessengerEXT (const overload - does not
  //! populate function pointer)
  XrResult
  xrDestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT messenger) const {

    return (reinterpret_cast<PFN_xrDestroyDebugUtilsMessengerEXT>(
        pfnDestroyDebugUtilsMessengerEXT))(messenger);
  }

  //! @brief Call xrSubmitDebugUtilsMessageEXT, populating function pointer if
  //! required.
  XrResult xrSubmitDebugUtilsMessageEXT(
      XrInstance instance, XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData) {

    XrResult result = populate_("xrSubmitDebugUtilsMessageEXT",
                                pfnSubmitDebugUtilsMessageEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSubmitDebugUtilsMessageEXT>(
        pfnSubmitDebugUtilsMessageEXT))(instance, messageSeverity, messageTypes,
                                        callbackData);
  }

  //! @brief Call xrSubmitDebugUtilsMessageEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSubmitDebugUtilsMessageEXT(
      XrInstance instance, XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData) const {

    return (reinterpret_cast<PFN_xrSubmitDebugUtilsMessageEXT>(
        pfnSubmitDebugUtilsMessageEXT))(instance, messageSeverity, messageTypes,
                                        callbackData);
  }

  //! @brief Call xrSessionBeginDebugUtilsLabelRegionEXT, populating function
  //! pointer if required.
  XrResult xrSessionBeginDebugUtilsLabelRegionEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) {

    XrResult result = populate_("xrSessionBeginDebugUtilsLabelRegionEXT",
                                pfnSessionBeginDebugUtilsLabelRegionEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionBeginDebugUtilsLabelRegionEXT>(
        pfnSessionBeginDebugUtilsLabelRegionEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionBeginDebugUtilsLabelRegionEXT (const overload - does
  //! not populate function pointer)
  XrResult xrSessionBeginDebugUtilsLabelRegionEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) const {

    return (reinterpret_cast<PFN_xrSessionBeginDebugUtilsLabelRegionEXT>(
        pfnSessionBeginDebugUtilsLabelRegionEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionEndDebugUtilsLabelRegionEXT, populating function
  //! pointer if required.
  XrResult xrSessionEndDebugUtilsLabelRegionEXT(XrSession session) {

    XrResult result = populate_("xrSessionEndDebugUtilsLabelRegionEXT",
                                pfnSessionEndDebugUtilsLabelRegionEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionEndDebugUtilsLabelRegionEXT>(
        pfnSessionEndDebugUtilsLabelRegionEXT))(session);
  }

  //! @brief Call xrSessionEndDebugUtilsLabelRegionEXT (const overload - does
  //! not populate function pointer)
  XrResult xrSessionEndDebugUtilsLabelRegionEXT(XrSession session) const {

    return (reinterpret_cast<PFN_xrSessionEndDebugUtilsLabelRegionEXT>(
        pfnSessionEndDebugUtilsLabelRegionEXT))(session);
  }

  //! @brief Call xrSessionInsertDebugUtilsLabelEXT, populating function pointer
  //! if required.
  XrResult
  xrSessionInsertDebugUtilsLabelEXT(XrSession session,
                                    const XrDebugUtilsLabelEXT *labelInfo) {

    XrResult result = populate_("xrSessionInsertDebugUtilsLabelEXT",
                                pfnSessionInsertDebugUtilsLabelEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionInsertDebugUtilsLabelEXT>(
        pfnSessionInsertDebugUtilsLabelEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionInsertDebugUtilsLabelEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSessionInsertDebugUtilsLabelEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) const {

    return (reinterpret_cast<PFN_xrSessionInsertDebugUtilsLabelEXT>(
        pfnSessionInsertDebugUtilsLabelEXT))(session, labelInfo);
  }

  //! @brief Call xrCreateSpatialAnchorMSFT, populating function pointer if
  //! required.
  XrResult
  xrCreateSpatialAnchorMSFT(XrSession session,
                            const XrSpatialAnchorCreateInfoMSFT *createInfo,
                            XrSpatialAnchorMSFT *anchor) {

    XrResult result =
        populate_("xrCreateSpatialAnchorMSFT", pfnCreateSpatialAnchorMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorMSFT>(
        pfnCreateSpatialAnchorMSFT))(session, createInfo, anchor);
  }

  //! @brief Call xrCreateSpatialAnchorMSFT (const overload - does not populate
  //! function pointer)
  XrResult
  xrCreateSpatialAnchorMSFT(XrSession session,
                            const XrSpatialAnchorCreateInfoMSFT *createInfo,
                            XrSpatialAnchorMSFT *anchor) const {

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorMSFT>(
        pfnCreateSpatialAnchorMSFT))(session, createInfo, anchor);
  }

  //! @brief Call xrCreateSpatialAnchorSpaceMSFT, populating function pointer if
  //! required.
  XrResult xrCreateSpatialAnchorSpaceMSFT(
      XrSession session, const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo,
      XrSpace *space) {

    XrResult result = populate_("xrCreateSpatialAnchorSpaceMSFT",
                                pfnCreateSpatialAnchorSpaceMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorSpaceMSFT>(
        pfnCreateSpatialAnchorSpaceMSFT))(session, createInfo, space);
  }

  //! @brief Call xrCreateSpatialAnchorSpaceMSFT (const overload - does not
  //! populate function pointer)
  XrResult xrCreateSpatialAnchorSpaceMSFT(
      XrSession session, const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo,
      XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorSpaceMSFT>(
        pfnCreateSpatialAnchorSpaceMSFT))(session, createInfo, space);
  }

  //! @brief Call xrDestroySpatialAnchorMSFT, populating function pointer if
  //! required.
  XrResult xrDestroySpatialAnchorMSFT(XrSpatialAnchorMSFT anchor) {

    XrResult result =
        populate_("xrDestroySpatialAnchorMSFT", pfnDestroySpatialAnchorMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySpatialAnchorMSFT>(
        pfnDestroySpatialAnchorMSFT))(anchor);
  }

  //! @brief Call xrDestroySpatialAnchorMSFT (const overload - does not populate
  //! function pointer)
  XrResult xrDestroySpatialAnchorMSFT(XrSpatialAnchorMSFT anchor) const {

    return (reinterpret_cast<PFN_xrDestroySpatialAnchorMSFT>(
        pfnDestroySpatialAnchorMSFT))(anchor);
  }

  //! @}
private:
  //! @brief Internal utility function to populate a function pointer if it is
  //! nullptr.
  XrResult populate_(const char *function_name, PFN_xrVoidFunction &pfn) {
    if (pfn == nullptr) {
      return reinterpret_cast<PFN_xrGetInstanceProcAddr>(
          pfnGetInstanceProcAddr)(m_instance.get(), function_name, &pfn);
    }
    return XR_SUCCESS;
  }
  Instance m_instance;
  PFN_xrVoidFunction pfnGetInstanceProcAddr{};
  PFN_xrVoidFunction pfnEnumerateApiLayerProperties{};
  PFN_xrVoidFunction pfnEnumerateInstanceExtensionProperties{};
  PFN_xrVoidFunction pfnCreateInstance{};
  PFN_xrVoidFunction pfnDestroyInstance{};
  PFN_xrVoidFunction pfnGetInstanceProperties{};
  PFN_xrVoidFunction pfnPollEvent{};
  PFN_xrVoidFunction pfnResultToString{};
  PFN_xrVoidFunction pfnStructureTypeToString{};
  PFN_xrVoidFunction pfnGetSystem{};
  PFN_xrVoidFunction pfnGetSystemProperties{};
  PFN_xrVoidFunction pfnEnumerateEnvironmentBlendModes{};
  PFN_xrVoidFunction pfnCreateSession{};
  PFN_xrVoidFunction pfnDestroySession{};
  PFN_xrVoidFunction pfnEnumerateReferenceSpaces{};
  PFN_xrVoidFunction pfnCreateReferenceSpace{};
  PFN_xrVoidFunction pfnGetReferenceSpaceBoundsRect{};
  PFN_xrVoidFunction pfnCreateActionSpace{};
  PFN_xrVoidFunction pfnLocateSpace{};
  PFN_xrVoidFunction pfnDestroySpace{};
  PFN_xrVoidFunction pfnEnumerateViewConfigurations{};
  PFN_xrVoidFunction pfnGetViewConfigurationProperties{};
  PFN_xrVoidFunction pfnEnumerateViewConfigurationViews{};
  PFN_xrVoidFunction pfnEnumerateSwapchainFormats{};
  PFN_xrVoidFunction pfnCreateSwapchain{};
  PFN_xrVoidFunction pfnDestroySwapchain{};
  PFN_xrVoidFunction pfnEnumerateSwapchainImages{};
  PFN_xrVoidFunction pfnAcquireSwapchainImage{};
  PFN_xrVoidFunction pfnWaitSwapchainImage{};
  PFN_xrVoidFunction pfnReleaseSwapchainImage{};
  PFN_xrVoidFunction pfnBeginSession{};
  PFN_xrVoidFunction pfnEndSession{};
  PFN_xrVoidFunction pfnRequestExitSession{};
  PFN_xrVoidFunction pfnWaitFrame{};
  PFN_xrVoidFunction pfnBeginFrame{};
  PFN_xrVoidFunction pfnEndFrame{};
  PFN_xrVoidFunction pfnLocateViews{};
  PFN_xrVoidFunction pfnStringToPath{};
  PFN_xrVoidFunction pfnPathToString{};
  PFN_xrVoidFunction pfnCreateActionSet{};
  PFN_xrVoidFunction pfnDestroyActionSet{};
  PFN_xrVoidFunction pfnCreateAction{};
  PFN_xrVoidFunction pfnDestroyAction{};
  PFN_xrVoidFunction pfnSuggestInteractionProfileBindings{};
  PFN_xrVoidFunction pfnAttachSessionActionSets{};
  PFN_xrVoidFunction pfnGetCurrentInteractionProfile{};
  PFN_xrVoidFunction pfnGetActionStateBoolean{};
  PFN_xrVoidFunction pfnGetActionStateFloat{};
  PFN_xrVoidFunction pfnGetActionStateVector2f{};
  PFN_xrVoidFunction pfnGetActionStatePose{};
  PFN_xrVoidFunction pfnSyncActions{};
  PFN_xrVoidFunction pfnEnumerateBoundSourcesForAction{};
  PFN_xrVoidFunction pfnGetInputSourceLocalizedName{};
  PFN_xrVoidFunction pfnApplyHapticFeedback{};
  PFN_xrVoidFunction pfnStopHapticFeedback{};
  PFN_xrVoidFunction pfnSetAndroidApplicationThreadKHR{};
  PFN_xrVoidFunction pfnCreateSwapchainAndroidSurfaceKHR{};
  PFN_xrVoidFunction pfnGetOpenGLGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetOpenGLESGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetVulkanInstanceExtensionsKHR{};
  PFN_xrVoidFunction pfnGetVulkanDeviceExtensionsKHR{};
  PFN_xrVoidFunction pfnGetVulkanGraphicsDeviceKHR{};
  PFN_xrVoidFunction pfnGetVulkanGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetD3D11GraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetD3D12GraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetVisibilityMaskKHR{};
  PFN_xrVoidFunction pfnConvertWin32PerformanceCounterToTimeKHR{};
  PFN_xrVoidFunction pfnConvertTimeToWin32PerformanceCounterKHR{};
  PFN_xrVoidFunction pfnConvertTimespecTimeToTimeKHR{};
  PFN_xrVoidFunction pfnConvertTimeToTimespecTimeKHR{};
  PFN_xrVoidFunction pfnPerfSettingsSetPerformanceLevelEXT{};
  PFN_xrVoidFunction pfnThermalGetTemperatureTrendEXT{};
  PFN_xrVoidFunction pfnSetDebugUtilsObjectNameEXT{};
  PFN_xrVoidFunction pfnCreateDebugUtilsMessengerEXT{};
  PFN_xrVoidFunction pfnDestroyDebugUtilsMessengerEXT{};
  PFN_xrVoidFunction pfnSubmitDebugUtilsMessageEXT{};
  PFN_xrVoidFunction pfnSessionBeginDebugUtilsLabelRegionEXT{};
  PFN_xrVoidFunction pfnSessionEndDebugUtilsLabelRegionEXT{};
  PFN_xrVoidFunction pfnSessionInsertDebugUtilsLabelEXT{};
  PFN_xrVoidFunction pfnCreateSpatialAnchorMSFT{};
  PFN_xrVoidFunction pfnCreateSpatialAnchorSpaceMSFT{};
  PFN_xrVoidFunction pfnDestroySpatialAnchorMSFT{};
};

} // namespace OPENXR_HPP_NAMESPACE

/*
 * Inline implementations of all trampoline methods and free functions follow.
 * Prototypes may be found above, either in the associated handle class, or
 * immediately following the section of handle classes.
 */

namespace OPENXR_HPP_NAMESPACE {

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getInstanceProcAddr(
    const char *name, PFN_xrVoidFunction *function, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetInstanceProcAddr(this->get(), name, function));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                              Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetInstanceProcAddr(this->get(), name, function));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getInstanceProcAddr");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result enumerateApiLayerProperties(
    uint32_t propertyCapacityInput, uint32_t *propertyCountOutput,
    XrApiLayerProperties *properties, Dispatch &&d) {
  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, propertyCountOutput, properties));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ApiLayerProperties, Allocator>>::type
    enumerateApiLayerProperties(Dispatch &&d) {
  // Two-call idiom
  ::std::vector<ApiLayerProperties, Allocator> properties;
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateApiLayerProperties");
  }
  do {
    properties.resize(propertyCountOutput);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
        propertyCapacityInput, &propertyCountOutput,
        reinterpret_cast<XrApiLayerProperties *>(properties.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateApiLayerProperties");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ApiLayerProperties, Allocator>>::type
    enumerateApiLayerProperties(Allocator const &vectorAllocator,
                                Dispatch &&d) {
  // Two-call idiom
  ::std::vector<ApiLayerProperties, Allocator> properties{vectorAllocator};
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateApiLayerProperties");
  }
  do {
    properties.resize(propertyCountOutput);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
        propertyCapacityInput, &propertyCountOutput,
        reinterpret_cast<XrApiLayerProperties *>(properties.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateApiLayerProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result enumerateInstanceExtensionProperties(
    const char *layerName, uint32_t propertyCapacityInput,
    uint32_t *propertyCountOutput, XrExtensionProperties *properties,
    Dispatch &&d) {
  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, propertyCountOutput, properties));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName, Dispatch &&d) {
  // Two-call idiom
  ::std::vector<ExtensionProperties, Allocator> properties;
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateInstanceExtensionProperties");
  }
  do {
    properties.resize(propertyCountOutput);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, &propertyCountOutput,
        reinterpret_cast<XrExtensionProperties *>(properties.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateInstanceExtensionProperties");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Allocator const &vectorAllocator,
                                     Dispatch &&d) {
  // Two-call idiom
  ::std::vector<ExtensionProperties, Allocator> properties{vectorAllocator};
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateInstanceExtensionProperties");
  }
  do {
    properties.resize(propertyCountOutput);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, &propertyCountOutput,
        reinterpret_cast<XrExtensionProperties *>(properties.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateInstanceExtensionProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result createInstance(const InstanceCreateInfo &createInfo,
                                        Instance &instance, Dispatch &&d) {
  Result result = static_cast<Result>(d.xrCreateInstance(
      &(createInfo.operator const XrInstanceCreateInfo &()), instance.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Instance>::type
createInstance(const InstanceCreateInfo &createInfo, Dispatch &&d) {
  Instance handle;
  Result result = static_cast<Result>(d.xrCreateInstance(
      &(createInfo.operator const XrInstanceCreateInfo &()), handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::createInstance");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Instance, impl::RemoveRefConst<Dispatch>>>::type
createInstanceUnique(const InstanceCreateInfo &createInfo, Dispatch &&d) {
  Instance handle;
  Result result = static_cast<Result>(d.xrCreateInstance(
      &(createInfo.operator const XrInstanceCreateInfo &()), handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Instance, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::createInstanceUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyInstance(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyInstance(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getInstanceProperties(
    InstanceProperties &instanceProperties, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetInstanceProperties(
      this->get(), &(instanceProperties.operator XrInstanceProperties &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<InstanceProperties>::type
Instance::getInstanceProperties(Dispatch &&d) const {
  InstanceProperties structResult;
  Result result = static_cast<Result>(d.xrGetInstanceProperties(
      this->get(), &(structResult.operator XrInstanceProperties &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getInstanceProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pollEvent(EventDataBuffer &eventData,
                                             Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrPollEvent(this->get(), &(eventData.operator XrEventDataBuffer &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pollEvent(EventDataBuffer &eventData,
                                             Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrPollEvent(this->get(), &(eventData.operator XrEventDataBuffer &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Instance::pollEvent",
      {Result::Success, Result::EventUnavailable});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::resultToString(
    Result value, char buffer[XR_MAX_RESULT_STRING_SIZE], Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrResultToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                         Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrResultToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::resultToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::structureTypeToString(
    StructureType value, char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStructureTypeToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::structureTypeToString(StructureType value,
                                char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                                Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStructureTypeToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::structureTypeToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getSystem(const SystemGetInfo &getInfo,
                                             XrSystemId *systemId,
                                             Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetSystem(
      this->get(), &(getInfo.operator const XrSystemGetInfo &()), systemId));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<SystemId>::type
Instance::getSystem(const SystemGetInfo &getInfo, Dispatch &&d) const {
  SystemId structResult;
  Result result = static_cast<Result>(
      d.xrGetSystem(this->get(), &(getInfo.operator const XrSystemGetInfo &()),
                    &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getSystem");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getSystemProperties(
    XrSystemId systemId, SystemProperties &properties, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetSystemProperties(
      this->get(), systemId, &(properties.operator XrSystemProperties &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<SystemProperties>::type
Instance::getSystemProperties(XrSystemId systemId, Dispatch &&d) const {
  SystemProperties structResult;
  Result result = static_cast<Result>(d.xrGetSystemProperties(
      this->get(), systemId, &(structResult.operator XrSystemProperties &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getSystemProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateEnvironmentBlendModes(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    uint32_t environmentBlendModeCapacityInput,
    uint32_t *environmentBlendModeCountOutput,
    XrEnvironmentBlendMode *environmentBlendModes, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
      environmentBlendModes));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<EnvironmentBlendMode, Allocator>>::type
Instance::enumerateEnvironmentBlendModes(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<EnvironmentBlendMode, Allocator> environmentBlendModes;
  uint32_t environmentBlendModeCountOutput = 0;
  uint32_t environmentBlendModeCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      environmentBlendModeCapacityInput, &environmentBlendModeCountOutput,
      nullptr));
  if (!unqualifiedSuccess(result) || environmentBlendModeCountOutput == 0) {

    return impl::createResultValue(
        result, environmentBlendModes,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateEnvironmentBlendModes");
  }
  do {
    environmentBlendModes.resize(environmentBlendModeCountOutput);
    environmentBlendModeCapacityInput =
        static_cast<uint32_t>(environmentBlendModes.size());
    result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        environmentBlendModeCapacityInput, &environmentBlendModeCountOutput,
        reinterpret_cast<XrEnvironmentBlendMode *>(
            environmentBlendModes.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(environmentBlendModeCountOutput <=
                      environmentBlendModes.size());
    environmentBlendModes.resize(environmentBlendModeCountOutput);
  }

  return impl::createResultValue(result, environmentBlendModes,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateEnvironmentBlendModes");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<EnvironmentBlendMode, Allocator>>::type
Instance::enumerateEnvironmentBlendModes(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<EnvironmentBlendMode, Allocator> environmentBlendModes{
      vectorAllocator};
  uint32_t environmentBlendModeCountOutput = 0;
  uint32_t environmentBlendModeCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      environmentBlendModeCapacityInput, &environmentBlendModeCountOutput,
      nullptr));
  if (!unqualifiedSuccess(result) || environmentBlendModeCountOutput == 0) {

    return impl::createResultValue(
        result, environmentBlendModes,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateEnvironmentBlendModes");
  }
  do {
    environmentBlendModes.resize(environmentBlendModeCountOutput);
    environmentBlendModeCapacityInput =
        static_cast<uint32_t>(environmentBlendModes.size());
    result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        environmentBlendModeCapacityInput, &environmentBlendModeCountOutput,
        reinterpret_cast<XrEnvironmentBlendMode *>(
            environmentBlendModes.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(environmentBlendModeCountOutput <=
                      environmentBlendModes.size());
    environmentBlendModes.resize(environmentBlendModeCountOutput);
  }

  return impl::createResultValue(result, environmentBlendModes,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateEnvironmentBlendModes");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::createSession(
    const SessionCreateInfo &createInfo, Session &session, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSession(
      this->get(), &(createInfo.operator const XrSessionCreateInfo &()),
      session.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Session>::type
Instance::createSession(const SessionCreateInfo &createInfo,
                        Dispatch &&d) const {
  Session handle;
  Result result = static_cast<Result>(d.xrCreateSession(
      this->get(), &(createInfo.operator const XrSessionCreateInfo &()),
      handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::Instance::createSession");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Session, impl::RemoveRefConst<Dispatch>>>::type
Instance::createSessionUnique(const SessionCreateInfo &createInfo,
                              Dispatch &&d) const {
  Session handle;
  Result result = static_cast<Result>(d.xrCreateSession(
      this->get(), &(createInfo.operator const XrSessionCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Session, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Instance::createSessionUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySession(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateReferenceSpaces(
    uint32_t spaceCapacityInput, uint32_t *spaceCountOutput,
    XrReferenceSpaceType *spaces, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, spaceCountOutput, spaces));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ReferenceSpaceType, Allocator>>::type
    Session::enumerateReferenceSpaces(Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ReferenceSpaceType, Allocator> spaces;
  uint32_t spaceCountOutput = 0;
  uint32_t spaceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, &spaceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || spaceCountOutput == 0) {

    return impl::createResultValue(result, spaces,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateReferenceSpaces");
  }
  do {
    spaces.resize(spaceCountOutput);
    spaceCapacityInput = static_cast<uint32_t>(spaces.size());
    result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
        this->get(), spaceCapacityInput, &spaceCountOutput,
        reinterpret_cast<XrReferenceSpaceType *>(spaces.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(spaceCountOutput <= spaces.size());
    spaces.resize(spaceCountOutput);
  }

  return impl::createResultValue(result, spaces,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateReferenceSpaces");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ReferenceSpaceType, Allocator>>::type
    Session::enumerateReferenceSpaces(Allocator const &vectorAllocator,
                                      Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ReferenceSpaceType, Allocator> spaces{vectorAllocator};
  uint32_t spaceCountOutput = 0;
  uint32_t spaceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, &spaceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || spaceCountOutput == 0) {

    return impl::createResultValue(result, spaces,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateReferenceSpaces");
  }
  do {
    spaces.resize(spaceCountOutput);
    spaceCapacityInput = static_cast<uint32_t>(spaces.size());
    result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
        this->get(), spaceCapacityInput, &spaceCountOutput,
        reinterpret_cast<XrReferenceSpaceType *>(spaces.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(spaceCountOutput <= spaces.size());
    spaces.resize(spaceCountOutput);
  }

  return impl::createResultValue(result, spaces,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateReferenceSpaces");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::createReferenceSpace(const ReferenceSpaceCreateInfo &createInfo,
                              Space &space, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateReferenceSpace(
      this->get(), &(createInfo.operator const XrReferenceSpaceCreateInfo &()),
      space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Space>::type
Session::createReferenceSpace(const ReferenceSpaceCreateInfo &createInfo,
                              Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateReferenceSpace(
      this->get(), &(createInfo.operator const XrReferenceSpaceCreateInfo &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createReferenceSpace");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
Session::createReferenceSpaceUnique(const ReferenceSpaceCreateInfo &createInfo,
                                    Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateReferenceSpace(
      this->get(), &(createInfo.operator const XrReferenceSpaceCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createReferenceSpaceUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     Extent2Df &bounds, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetReferenceSpaceBoundsRect(
      this->get(), OPENXR_HPP_NAMESPACE::get(referenceSpaceType),
      &(bounds.operator XrExtent2Df &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     Extent2Df &bounds, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetReferenceSpaceBoundsRect(
      this->get(), OPENXR_HPP_NAMESPACE::get(referenceSpaceType),
      &(bounds.operator XrExtent2Df &())));
  return impl::createResultValue(
      result,
      OPENXR_HPP_NAMESPACE_STRING "::Session::getReferenceSpaceBoundsRect",
      {Result::Success, Result::SpaceBoundsUnavailable});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createActionSpace(
    const ActionSpaceCreateInfo &createInfo, Space &space, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateActionSpace(
      this->get(), &(createInfo.operator const XrActionSpaceCreateInfo &()),
      space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Space>::type
Session::createActionSpace(const ActionSpaceCreateInfo &createInfo,
                           Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateActionSpace(
      this->get(), &(createInfo.operator const XrActionSpaceCreateInfo &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createActionSpace");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
Session::createActionSpaceUnique(const ActionSpaceCreateInfo &createInfo,
                                 Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateActionSpace(
      this->get(), &(createInfo.operator const XrActionSpaceCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createActionSpaceUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Space::locateSpace(Space baseSpace, XrTime time,
                                            SpaceLocation &location,
                                            Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrLocateSpace(this->get(), baseSpace.get(), time,
                      &(location.operator XrSpaceLocation &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<SpaceLocation>::type
Space::locateSpace(Space baseSpace, XrTime time, Dispatch &&d) const {
  SpaceLocation structResult;
  Result result = static_cast<Result>(
      d.xrLocateSpace(this->get(), baseSpace.get(), time,
                      &(structResult.operator XrSpaceLocation &())));
  return impl::createResultValue(
      result, structResult, OPENXR_HPP_NAMESPACE_STRING "::Space::locateSpace");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Space::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySpace(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Space::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySpace(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Space::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateViewConfigurations(
    XrSystemId systemId, uint32_t viewConfigurationTypeCapacityInput,
    uint32_t *viewConfigurationTypeCountOutput,
    XrViewConfigurationType *viewConfigurationTypes, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateViewConfigurations(
      this->get(), systemId, viewConfigurationTypeCapacityInput,
      viewConfigurationTypeCountOutput, viewConfigurationTypes));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ViewConfigurationType, Allocator>>::type
Instance::enumerateViewConfigurations(XrSystemId systemId, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ViewConfigurationType, Allocator> viewConfigurationTypes;
  uint32_t viewConfigurationTypeCountOutput = 0;
  uint32_t viewConfigurationTypeCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurations(
      this->get(), systemId, viewConfigurationTypeCapacityInput,
      &viewConfigurationTypeCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewConfigurationTypeCountOutput == 0) {

    return impl::createResultValue(result, viewConfigurationTypes,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::enumerateViewConfigurations");
  }
  do {
    viewConfigurationTypes.resize(viewConfigurationTypeCountOutput);
    viewConfigurationTypeCapacityInput =
        static_cast<uint32_t>(viewConfigurationTypes.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurations(
        this->get(), systemId, viewConfigurationTypeCapacityInput,
        &viewConfigurationTypeCountOutput,
        reinterpret_cast<XrViewConfigurationType *>(
            viewConfigurationTypes.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewConfigurationTypeCountOutput <=
                      viewConfigurationTypes.size());
    viewConfigurationTypes.resize(viewConfigurationTypeCountOutput);
  }

  return impl::createResultValue(result, viewConfigurationTypes,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurations");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ViewConfigurationType, Allocator>>::type
Instance::enumerateViewConfigurations(XrSystemId systemId,
                                      Allocator const &vectorAllocator,
                                      Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ViewConfigurationType, Allocator> viewConfigurationTypes{
      vectorAllocator};
  uint32_t viewConfigurationTypeCountOutput = 0;
  uint32_t viewConfigurationTypeCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurations(
      this->get(), systemId, viewConfigurationTypeCapacityInput,
      &viewConfigurationTypeCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewConfigurationTypeCountOutput == 0) {

    return impl::createResultValue(result, viewConfigurationTypes,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::enumerateViewConfigurations");
  }
  do {
    viewConfigurationTypes.resize(viewConfigurationTypeCountOutput);
    viewConfigurationTypeCapacityInput =
        static_cast<uint32_t>(viewConfigurationTypes.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurations(
        this->get(), systemId, viewConfigurationTypeCapacityInput,
        &viewConfigurationTypeCountOutput,
        reinterpret_cast<XrViewConfigurationType *>(
            viewConfigurationTypes.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewConfigurationTypeCountOutput <=
                      viewConfigurationTypes.size());
    viewConfigurationTypes.resize(viewConfigurationTypeCountOutput);
  }

  return impl::createResultValue(result, viewConfigurationTypes,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurations");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getViewConfigurationProperties(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    ViewConfigurationProperties &configurationProperties, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetViewConfigurationProperties(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      &(configurationProperties.operator XrViewConfigurationProperties &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ViewConfigurationProperties>::type
Instance::getViewConfigurationProperties(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Dispatch &&d) const {
  ViewConfigurationProperties structResult;
  Result result = static_cast<Result>(d.xrGetViewConfigurationProperties(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      &(structResult.operator XrViewConfigurationProperties &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getViewConfigurationProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    uint32_t viewCapacityInput, uint32_t *viewCountOutput,
    XrViewConfigurationView *views, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, viewCountOutput, views));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ViewConfigurationView, Allocator>>::type
Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ViewConfigurationView, Allocator> views;
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateViewConfigurationViews");
  }
  do {
    views.resize(viewCountOutput);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        viewCapacityInput, &viewCountOutput,
        reinterpret_cast<XrViewConfigurationView *>(views.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput);
  }

  return impl::createResultValue(result, views,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurationViews");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::vector<ViewConfigurationView, Allocator>>::type
Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ViewConfigurationView, Allocator> views{vectorAllocator};
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateViewConfigurationViews");
  }
  do {
    views.resize(viewCountOutput);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        viewCapacityInput, &viewCountOutput,
        reinterpret_cast<XrViewConfigurationView *>(views.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput);
  }

  return impl::createResultValue(result, views,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurationViews");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateSwapchainFormats(
    uint32_t formatCapacityInput, uint32_t *formatCountOutput, int64_t *formats,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, formatCountOutput, formats));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<int64_t, Allocator>>::type
    Session::enumerateSwapchainFormats(Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<int64_t, Allocator> formats;
  uint32_t formatCountOutput = 0;
  uint32_t formatCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, &formatCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || formatCountOutput == 0) {

    return impl::createResultValue(result, formats,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateSwapchainFormats");
  }
  do {
    formats.resize(formatCountOutput);
    formatCapacityInput = static_cast<uint32_t>(formats.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
        this->get(), formatCapacityInput, &formatCountOutput,
        reinterpret_cast<int64_t *>(formats.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(formatCountOutput <= formats.size());
    formats.resize(formatCountOutput);
  }

  return impl::createResultValue(result, formats,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateSwapchainFormats");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<int64_t, Allocator>>::type
    Session::enumerateSwapchainFormats(Allocator const &vectorAllocator,
                                       Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<int64_t, Allocator> formats{vectorAllocator};
  uint32_t formatCountOutput = 0;
  uint32_t formatCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, &formatCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || formatCountOutput == 0) {

    return impl::createResultValue(result, formats,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateSwapchainFormats");
  }
  do {
    formats.resize(formatCountOutput);
    formatCapacityInput = static_cast<uint32_t>(formats.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
        this->get(), formatCapacityInput, &formatCountOutput,
        reinterpret_cast<int64_t *>(formats.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(formatCountOutput <= formats.size());
    formats.resize(formatCountOutput);
  }

  return impl::createResultValue(result, formats,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateSwapchainFormats");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::createSwapchain(const SwapchainCreateInfo &createInfo,
                         Swapchain &swapchain, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSwapchain(
      this->get(), &(createInfo.operator const XrSwapchainCreateInfo &()),
      swapchain.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Swapchain>::type
Session::createSwapchain(const SwapchainCreateInfo &createInfo,
                         Dispatch &&d) const {
  Swapchain handle;
  Result result = static_cast<Result>(d.xrCreateSwapchain(
      this->get(), &(createInfo.operator const XrSwapchainCreateInfo &()),
      handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::Session::createSwapchain");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>>::type
Session::createSwapchainUnique(const SwapchainCreateInfo &createInfo,
                               Dispatch &&d) const {
  Swapchain handle;
  Result result = static_cast<Result>(d.xrCreateSwapchain(
      this->get(), &(createInfo.operator const XrSwapchainCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Swapchain, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createSwapchainUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySwapchain(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Swapchain::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySwapchain(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::enumerateSwapchainImages(
    uint32_t imageCapacityInput, uint32_t *imageCountOutput,
    XrSwapchainImageBaseHeader *images, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateSwapchainImages(
      this->get(), imageCapacityInput, imageCountOutput, images));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename ResultItemType, typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ResultItemType, Allocator>>::type
    Swapchain::enumerateSwapchainImages(Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ResultItemType, Allocator> images;
  uint32_t imageCountOutput = 0;
  uint32_t imageCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainImages(
      this->get(), imageCapacityInput, &imageCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || imageCountOutput == 0) {

    return impl::createResultValue(result, images,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Swapchain::enumerateSwapchainImages");
  }
  do {
    images.resize(imageCountOutput);
    imageCapacityInput = static_cast<uint32_t>(images.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainImages(
        this->get(), imageCapacityInput, &imageCountOutput,
        reinterpret_cast<XrSwapchainImageBaseHeader *>(images.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(imageCountOutput <= images.size());
    images.resize(imageCountOutput);
  }

  return impl::createResultValue(result, images,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::enumerateSwapchainImages");
}

template <typename ResultItemType, typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<::std::vector<ResultItemType, Allocator>>::type
    Swapchain::enumerateSwapchainImages(Allocator const &vectorAllocator,
                                        Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<ResultItemType, Allocator> images{vectorAllocator};
  uint32_t imageCountOutput = 0;
  uint32_t imageCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainImages(
      this->get(), imageCapacityInput, &imageCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || imageCountOutput == 0) {

    return impl::createResultValue(result, images,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Swapchain::enumerateSwapchainImages");
  }
  do {
    images.resize(imageCountOutput);
    imageCapacityInput = static_cast<uint32_t>(images.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainImages(
        this->get(), imageCapacityInput, &imageCountOutput,
        reinterpret_cast<XrSwapchainImageBaseHeader *>(images.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(imageCountOutput <= images.size());
    images.resize(imageCountOutput);
  }

  return impl::createResultValue(result, images,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::enumerateSwapchainImages");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Swapchain::acquireSwapchainImage(const SwapchainImageAcquireInfo &acquireInfo,
                                 uint32_t *index, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrAcquireSwapchainImage(
      this->get(),
      &(acquireInfo.operator const XrSwapchainImageAcquireInfo &()), index));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<uint32_t>::type
Swapchain::acquireSwapchainImage(const SwapchainImageAcquireInfo &acquireInfo,
                                 Dispatch &&d) const {
  uint32_t structResult;
  Result result = static_cast<Result>(d.xrAcquireSwapchainImage(
      this->get(),
      &(acquireInfo.operator const XrSwapchainImageAcquireInfo &()),
      &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::acquireSwapchainImage");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::waitSwapchainImage(
    const SwapchainImageWaitInfo &waitInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrWaitSwapchainImage(
      this->get(), &(waitInfo.operator const XrSwapchainImageWaitInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::waitSwapchainImage(
    const SwapchainImageWaitInfo &waitInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrWaitSwapchainImage(
      this->get(), &(waitInfo.operator const XrSwapchainImageWaitInfo &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Swapchain::waitSwapchainImage",
      {Result::Success, Result::TimeoutExpired});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::releaseSwapchainImage(
    const SwapchainImageReleaseInfo &releaseInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrReleaseSwapchainImage(
      this->get(),
      &(releaseInfo.operator const XrSwapchainImageReleaseInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Swapchain::releaseSwapchainImage(const SwapchainImageReleaseInfo &releaseInfo,
                                 Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrReleaseSwapchainImage(
      this->get(),
      &(releaseInfo.operator const XrSwapchainImageReleaseInfo &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::releaseSwapchainImage");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::beginSession(const SessionBeginInfo &beginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginSession(
      this->get(), &(beginInfo.operator const XrSessionBeginInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::beginSession(const SessionBeginInfo &beginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginSession(
      this->get(), &(beginInfo.operator const XrSessionBeginInfo &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::beginSession");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndSession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::endSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndSession(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::endSession");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::requestExitSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrRequestExitSession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::requestExitSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrRequestExitSession(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::requestExitSession");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::waitFrame(const FrameWaitInfo &frameWaitInfo,
                                            FrameState &frameState,
                                            Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrWaitFrame(
      this->get(), &(frameWaitInfo.operator const XrFrameWaitInfo &()),
      &(frameState.operator XrFrameState &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<FrameState>::type
Session::waitFrame(const FrameWaitInfo &frameWaitInfo, Dispatch &&d) const {
  FrameState structResult;
  Result result = static_cast<Result>(d.xrWaitFrame(
      this->get(), &(frameWaitInfo.operator const XrFrameWaitInfo &()),
      &(structResult.operator XrFrameState &())));
  return impl::createResultValue(
      result, structResult, OPENXR_HPP_NAMESPACE_STRING "::Session::waitFrame");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::beginFrame(const FrameBeginInfo &frameBeginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginFrame(
      this->get(), &(frameBeginInfo.operator const XrFrameBeginInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::beginFrame(const FrameBeginInfo &frameBeginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginFrame(
      this->get(), &(frameBeginInfo.operator const XrFrameBeginInfo &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::beginFrame",
      {Result::Success, Result::FrameDiscarded});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endFrame(const FrameEndInfo &frameEndInfo,
                                           Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndFrame(
      this->get(), &(frameEndInfo.operator const XrFrameEndInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::endFrame(const FrameEndInfo &frameEndInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndFrame(
      this->get(), &(frameEndInfo.operator const XrFrameEndInfo &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::endFrame");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::locateViews(
    const ViewLocateInfo &viewLocateInfo, XrViewState *viewState,
    uint32_t viewCapacityInput, uint32_t *viewCountOutput, XrView *views,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrLocateViews(
      this->get(), &(viewLocateInfo.operator const XrViewLocateInfo &()),
      viewState, viewCapacityInput, viewCountOutput, views));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<::std::vector<View, Allocator>>::type
Session::locateViews(const ViewLocateInfo &viewLocateInfo,
                     XrViewState *viewState, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<View, Allocator> views;
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  Result result = static_cast<Result>(d.xrLocateViews(
      this->get(), &(viewLocateInfo.operator const XrViewLocateInfo &()),
      viewState, viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews");
  }
  do {
    views.resize(viewCountOutput);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrLocateViews(
        this->get(), &(viewLocateInfo.operator const XrViewLocateInfo &()),
        viewState, viewCapacityInput, &viewCountOutput,
        reinterpret_cast<XrView *>(views.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput);
  }

  return impl::createResultValue(
      result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<::std::vector<View, Allocator>>::type
Session::locateViews(const ViewLocateInfo &viewLocateInfo,
                     XrViewState *viewState, Allocator const &vectorAllocator,
                     Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<View, Allocator> views{vectorAllocator};
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  Result result = static_cast<Result>(d.xrLocateViews(
      this->get(), &(viewLocateInfo.operator const XrViewLocateInfo &()),
      viewState, viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews");
  }
  do {
    views.resize(viewCountOutput);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrLocateViews(
        this->get(), &(viewLocateInfo.operator const XrViewLocateInfo &()),
        viewState, viewCapacityInput, &viewCountOutput,
        reinterpret_cast<XrView *>(views.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput);
  }

  return impl::createResultValue(
      result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::stringToPath(const char *pathString,
                                                XrPath *path,
                                                Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrStringToPath(this->get(), pathString, path));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Path>::type
Instance::stringToPath(const char *pathString, Dispatch &&d) const {
  Path structResult;
  Result result = static_cast<Result>(
      d.xrStringToPath(this->get(), pathString, &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::stringToPath");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pathToString(XrPath path,
                                                uint32_t bufferCapacityInput,
                                                uint32_t *bufferCountOutput,
                                                char *buffer,
                                                Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::pathToString(XrPath path, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrPathToString(
        this->get(), path, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(
      result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::pathToString(XrPath path, Allocator const &vectorAllocator,
                       Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrPathToString(
        this->get(), path, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(
      result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Instance::createActionSet(const ActionSetCreateInfo &createInfo,
                          ActionSet &actionSet, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateActionSet(
      this->get(), &(createInfo.operator const XrActionSetCreateInfo &()),
      actionSet.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionSet>::type
Instance::createActionSet(const ActionSetCreateInfo &createInfo,
                          Dispatch &&d) const {
  ActionSet handle;
  Result result = static_cast<Result>(d.xrCreateActionSet(
      this->get(), &(createInfo.operator const XrActionSetCreateInfo &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::createActionSet");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<ActionSet, impl::RemoveRefConst<Dispatch>>>::type
Instance::createActionSetUnique(const ActionSetCreateInfo &createInfo,
                                Dispatch &&d) const {
  ActionSet handle;
  Result result = static_cast<Result>(d.xrCreateActionSet(
      this->get(), &(createInfo.operator const XrActionSetCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<ActionSet, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Instance::createActionSetUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result ActionSet::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyActionSet(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
ActionSet::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyActionSet(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::ActionSet::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result ActionSet::createAction(
    const ActionCreateInfo &createInfo, Action &action, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateAction(
      this->get(), &(createInfo.operator const XrActionCreateInfo &()),
      action.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Action>::type
ActionSet::createAction(const ActionCreateInfo &createInfo,
                        Dispatch &&d) const {
  Action handle;
  Result result = static_cast<Result>(d.xrCreateAction(
      this->get(), &(createInfo.operator const XrActionCreateInfo &()),
      handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::ActionSet::createAction");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Action, impl::RemoveRefConst<Dispatch>>>::type
ActionSet::createActionUnique(const ActionCreateInfo &createInfo,
                              Dispatch &&d) const {
  Action handle;
  Result result = static_cast<Result>(d.xrCreateAction(
      this->get(), &(createInfo.operator const XrActionCreateInfo &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Action, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::ActionSet::createActionUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Action::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyAction(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Action::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyAction(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Action::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::suggestInteractionProfileBindings(
    const InteractionProfileSuggestedBinding &suggestedBindings,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSuggestInteractionProfileBindings(
      this->get(), &(suggestedBindings.
                     operator const XrInteractionProfileSuggestedBinding &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::suggestInteractionProfileBindings(
    const InteractionProfileSuggestedBinding &suggestedBindings,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSuggestInteractionProfileBindings(
      this->get(), &(suggestedBindings.
                     operator const XrInteractionProfileSuggestedBinding &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::suggestInteractionProfileBindings");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::attachSessionActionSets(
    const SessionActionSetsAttachInfo &attachInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrAttachSessionActionSets(
      this->get(),
      &(attachInfo.operator const XrSessionActionSetsAttachInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::attachSessionActionSets(const SessionActionSetsAttachInfo &attachInfo,
                                 Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrAttachSessionActionSets(
      this->get(),
      &(attachInfo.operator const XrSessionActionSetsAttachInfo &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::attachSessionActionSets");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getCurrentInteractionProfile(
    XrPath topLevelUserPath, InteractionProfileState &interactionProfile,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetCurrentInteractionProfile(
      this->get(), topLevelUserPath,
      &(interactionProfile.operator XrInteractionProfileState &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<InteractionProfileState>::type
Session::getCurrentInteractionProfile(XrPath topLevelUserPath,
                                      Dispatch &&d) const {
  InteractionProfileState structResult;
  Result result = static_cast<Result>(d.xrGetCurrentInteractionProfile(
      this->get(), topLevelUserPath,
      &(structResult.operator XrInteractionProfileState &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getCurrentInteractionProfile");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStateBoolean(const ActionStateGetInfo &getInfo,
                               ActionStateBoolean &state, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetActionStateBoolean(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(state.operator XrActionStateBoolean &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionStateBoolean>::type
Session::getActionStateBoolean(const ActionStateGetInfo &getInfo,
                               Dispatch &&d) const {
  ActionStateBoolean structResult;
  Result result = static_cast<Result>(d.xrGetActionStateBoolean(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(structResult.operator XrActionStateBoolean &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getActionStateBoolean");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStateFloat(const ActionStateGetInfo &getInfo,
                             ActionStateFloat &state, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetActionStateFloat(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(state.operator XrActionStateFloat &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionStateFloat>::type
Session::getActionStateFloat(const ActionStateGetInfo &getInfo,
                             Dispatch &&d) const {
  ActionStateFloat structResult;
  Result result = static_cast<Result>(d.xrGetActionStateFloat(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(structResult.operator XrActionStateFloat &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getActionStateFloat");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getActionStateVector2f(
    const ActionStateGetInfo &getInfo, ActionStateVector2f &state,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetActionStateVector2f(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(state.operator XrActionStateVector2f &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionStateVector2f>::type
Session::getActionStateVector2f(const ActionStateGetInfo &getInfo,
                                Dispatch &&d) const {
  ActionStateVector2f structResult;
  Result result = static_cast<Result>(d.xrGetActionStateVector2f(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(structResult.operator XrActionStateVector2f &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getActionStateVector2f");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStatePose(const ActionStateGetInfo &getInfo,
                            ActionStatePose &state, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetActionStatePose(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(state.operator XrActionStatePose &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionStatePose>::type
Session::getActionStatePose(const ActionStateGetInfo &getInfo,
                            Dispatch &&d) const {
  ActionStatePose structResult;
  Result result = static_cast<Result>(d.xrGetActionStatePose(
      this->get(), &(getInfo.operator const XrActionStateGetInfo &()),
      &(structResult.operator XrActionStatePose &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getActionStatePose");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::syncActions(const ActionsSyncInfo &syncInfo,
                                              Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSyncActions(
      this->get(), &(syncInfo.operator const XrActionsSyncInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::syncActions(const ActionsSyncInfo &syncInfo,
                                              Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSyncActions(
      this->get(), &(syncInfo.operator const XrActionsSyncInfo &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::syncActions",
      {Result::Success, Result::SessionNotFocused});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateBoundSourcesForAction(
    const BoundSourcesForActionEnumerateInfo &enumerateInfo,
    uint32_t sourceCapacityInput, uint32_t *sourceCountOutput, XrPath *sources,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(),
      &(enumerateInfo.operator const XrBoundSourcesForActionEnumerateInfo &()),
      sourceCapacityInput, sourceCountOutput, sources));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<::std::vector<Path, Allocator>>::type
Session::enumerateBoundSourcesForAction(
    const BoundSourcesForActionEnumerateInfo &enumerateInfo,
    Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<Path, Allocator> sources;
  uint32_t sourceCountOutput = 0;
  uint32_t sourceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(),
      &(enumerateInfo.operator const XrBoundSourcesForActionEnumerateInfo &()),
      sourceCapacityInput, &sourceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || sourceCountOutput == 0) {

    return impl::createResultValue(result, sources,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateBoundSourcesForAction");
  }
  do {
    sources.resize(sourceCountOutput);
    sourceCapacityInput = static_cast<uint32_t>(sources.size());
    result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
        this->get(),
        &(enumerateInfo.operator const XrBoundSourcesForActionEnumerateInfo
              &()),
        sourceCapacityInput, &sourceCountOutput,
        reinterpret_cast<XrPath *>(sources.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(sourceCountOutput <= sources.size());
    sources.resize(sourceCountOutput);
  }

  return impl::createResultValue(result, sources,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateBoundSourcesForAction");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<::std::vector<Path, Allocator>>::type
Session::enumerateBoundSourcesForAction(
    const BoundSourcesForActionEnumerateInfo &enumerateInfo,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<Path, Allocator> sources{vectorAllocator};
  uint32_t sourceCountOutput = 0;
  uint32_t sourceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(),
      &(enumerateInfo.operator const XrBoundSourcesForActionEnumerateInfo &()),
      sourceCapacityInput, &sourceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || sourceCountOutput == 0) {

    return impl::createResultValue(result, sources,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::enumerateBoundSourcesForAction");
  }
  do {
    sources.resize(sourceCountOutput);
    sourceCapacityInput = static_cast<uint32_t>(sources.size());
    result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
        this->get(),
        &(enumerateInfo.operator const XrBoundSourcesForActionEnumerateInfo
              &()),
        sourceCapacityInput, &sourceCountOutput,
        reinterpret_cast<XrPath *>(sources.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(sourceCountOutput <= sources.size());
    sources.resize(sourceCountOutput);
  }

  return impl::createResultValue(result, sources,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateBoundSourcesForAction");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getInputSourceLocalizedName(
    const InputSourceLocalizedNameGetInfo &getInfo,
    uint32_t bufferCapacityInput, uint32_t *bufferCountOutput, char *buffer,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(),
      &(getInfo.operator const XrInputSourceLocalizedNameGetInfo &()),
      bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Session::getInputSourceLocalizedName(
    const InputSourceLocalizedNameGetInfo &getInfo, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(),
      &(getInfo.operator const XrInputSourceLocalizedNameGetInfo &()),
      bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::getInputSourceLocalizedName");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
        this->get(),
        &(getInfo.operator const XrInputSourceLocalizedNameGetInfo &()),
        bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getInputSourceLocalizedName");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Session::getInputSourceLocalizedName(
    const InputSourceLocalizedNameGetInfo &getInfo,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(),
      &(getInfo.operator const XrInputSourceLocalizedNameGetInfo &()),
      bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Session::getInputSourceLocalizedName");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
        this->get(),
        &(getInfo.operator const XrInputSourceLocalizedNameGetInfo &()),
        bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getInputSourceLocalizedName");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::applyHapticFeedback(
    const HapticActionInfo &hapticActionInfo,
    const XrHapticBaseHeader *hapticFeedback, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrApplyHapticFeedback(
      this->get(), &(hapticActionInfo.operator const XrHapticActionInfo &()),
      hapticFeedback));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::applyHapticFeedback(const HapticActionInfo &hapticActionInfo,
                             const XrHapticBaseHeader *hapticFeedback,
                             Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrApplyHapticFeedback(
      this->get(), &(hapticActionInfo.operator const XrHapticActionInfo &()),
      hapticFeedback));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::applyHapticFeedback");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::stopHapticFeedback(
    const HapticActionInfo &hapticActionInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStopHapticFeedback(
      this->get(), &(hapticActionInfo.operator const XrHapticActionInfo &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::stopHapticFeedback(const HapticActionInfo &hapticActionInfo,
                            Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStopHapticFeedback(
      this->get(), &(hapticActionInfo.operator const XrHapticActionInfo &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::stopHapticFeedback");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_ANDROID)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::setAndroidApplicationThreadKHR(
    AndroidThreadTypeKHR threadType, uint32_t threadId, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetAndroidApplicationThreadKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(threadType), threadId));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::setAndroidApplicationThreadKHR(AndroidThreadTypeKHR threadType,
                                        uint32_t threadId, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetAndroidApplicationThreadKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(threadType), threadId));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::setAndroidApplicationThreadKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSwapchainAndroidSurfaceKHR(
    const SwapchainCreateInfo &info, Swapchain &swapchain, jobject *surface,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), &(info.operator const XrSwapchainCreateInfo &()),
      swapchain.put(), surface));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<jobject>::type
Session::createSwapchainAndroidSurfaceKHR(const SwapchainCreateInfo &info,
                                          Swapchain &swapchain,
                                          Dispatch &&d) const {
  jobject handle;
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), &(info.operator const XrSwapchainCreateInfo &()),
      swapchain.put(), handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSwapchainAndroidSurfaceKHR");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>>::type
Session::createSwapchainAndroidSurfaceUniqueKHR(const SwapchainCreateInfo &info,
                                                Swapchain &swapchain,
                                                Dispatch &&d) const {
  jobject handle;
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), &(info.operator const XrSwapchainCreateInfo &()),
      swapchain.put(), handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<jobject, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::createSwapchainAndroidSurfaceUniqueKHR");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_GRAPHICS_API_OPENGL)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getOpenGLGraphicsRequirementsKHR(
    XrSystemId systemId, GraphicsRequirementsOpenGLKHR &graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLGraphicsRequirementsKHR(
      this->get(), systemId,
      &(graphicsRequirements.operator XrGraphicsRequirementsOpenGLKHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<GraphicsRequirementsOpenGLKHR>::type
Instance::getOpenGLGraphicsRequirementsKHR(XrSystemId systemId,
                                           Dispatch &&d) const {
  GraphicsRequirementsOpenGLKHR structResult;
  Result result = static_cast<Result>(d.xrGetOpenGLGraphicsRequirementsKHR(
      this->get(), systemId,
      &(structResult.operator XrGraphicsRequirementsOpenGLKHR &())));
  return impl::createResultValue(
      result, structResult,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getOpenGLGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getOpenGLESGraphicsRequirementsKHR(
    XrSystemId systemId, GraphicsRequirementsOpenGLESKHR &graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLESGraphicsRequirementsKHR(
      this->get(), systemId,
      &(graphicsRequirements.operator XrGraphicsRequirementsOpenGLESKHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<GraphicsRequirementsOpenGLESKHR>::type
    Instance::getOpenGLESGraphicsRequirementsKHR(XrSystemId systemId,
                                                 Dispatch &&d) const {
  GraphicsRequirementsOpenGLESKHR structResult;
  Result result = static_cast<Result>(d.xrGetOpenGLESGraphicsRequirementsKHR(
      this->get(), systemId,
      &(structResult.operator XrGraphicsRequirementsOpenGLESKHR &())));
  return impl::createResultValue(
      result, structResult,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getOpenGLESGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanInstanceExtensionsKHR(
    XrSystemId systemId, uint32_t bufferCapacityInput,
    uint32_t *bufferCountOutput, char *buffer, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                         Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::getVulkanInstanceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanInstanceExtensionsKHR");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                         Allocator const &vectorAllocator,
                                         Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::getVulkanInstanceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanInstanceExtensionsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanDeviceExtensionsKHR(
    XrSystemId systemId, uint32_t bufferCapacityInput,
    uint32_t *bufferCountOutput, char *buffer, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                       Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::getVulkanDeviceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanDeviceExtensionsKHR");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    ::std::basic_string<char, ::std::char_traits<char>, Allocator>>::type
Instance::getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                       Allocator const &vectorAllocator,
                                       Dispatch &&d) const {
  // Two-call idiom
  ::std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::getVulkanDeviceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        reinterpret_cast<char *>(buffer.data())));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanDeviceExtensionsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanGraphicsDeviceKHR(
    XrSystemId systemId, VkInstance vkInstance,
    VkPhysicalDevice *vkPhysicalDevice, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsDeviceKHR(
      this->get(), systemId, vkInstance, vkPhysicalDevice));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<VkPhysicalDevice>::type
Instance::getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                                     Dispatch &&d) const {
  VkPhysicalDevice structResult;
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsDeviceKHR(
      this->get(), systemId, vkInstance, &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanGraphicsDeviceKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanGraphicsRequirementsKHR(
    XrSystemId systemId, GraphicsRequirementsVulkanKHR &graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsRequirementsKHR(
      this->get(), systemId,
      &(graphicsRequirements.operator XrGraphicsRequirementsVulkanKHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<GraphicsRequirementsVulkanKHR>::type
Instance::getVulkanGraphicsRequirementsKHR(XrSystemId systemId,
                                           Dispatch &&d) const {
  GraphicsRequirementsVulkanKHR structResult;
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsRequirementsKHR(
      this->get(), systemId,
      &(structResult.operator XrGraphicsRequirementsVulkanKHR &())));
  return impl::createResultValue(
      result, structResult,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getVulkanGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getD3D11GraphicsRequirementsKHR(
    XrSystemId systemId, GraphicsRequirementsD3D11KHR &graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D11GraphicsRequirementsKHR(
      this->get(), systemId,
      &(graphicsRequirements.operator XrGraphicsRequirementsD3D11KHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<GraphicsRequirementsD3D11KHR>::type
Instance::getD3D11GraphicsRequirementsKHR(XrSystemId systemId,
                                          Dispatch &&d) const {
  GraphicsRequirementsD3D11KHR structResult;
  Result result = static_cast<Result>(d.xrGetD3D11GraphicsRequirementsKHR(
      this->get(), systemId,
      &(structResult.operator XrGraphicsRequirementsD3D11KHR &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getD3D11GraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getD3D12GraphicsRequirementsKHR(
    XrSystemId systemId, GraphicsRequirementsD3D12KHR &graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D12GraphicsRequirementsKHR(
      this->get(), systemId,
      &(graphicsRequirements.operator XrGraphicsRequirementsD3D12KHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<GraphicsRequirementsD3D12KHR>::type
Instance::getD3D12GraphicsRequirementsKHR(XrSystemId systemId,
                                          Dispatch &&d) const {
  GraphicsRequirementsD3D12KHR structResult;
  Result result = static_cast<Result>(d.xrGetD3D12GraphicsRequirementsKHR(
      this->get(), systemId,
      &(structResult.operator XrGraphicsRequirementsD3D12KHR &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getD3D12GraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D12)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getVisibilityMaskKHR(
    ViewConfigurationType viewConfigurationType, uint32_t viewIndex,
    VisibilityMaskTypeKHR visibilityMaskType, VisibilityMaskKHR &visibilityMask,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVisibilityMaskKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(viewConfigurationType), viewIndex,
      OPENXR_HPP_NAMESPACE::get(visibilityMaskType),
      &(visibilityMask.operator XrVisibilityMaskKHR &())));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<VisibilityMaskKHR>::type
Session::getVisibilityMaskKHR(ViewConfigurationType viewConfigurationType,
                              uint32_t viewIndex,
                              VisibilityMaskTypeKHR visibilityMaskType,
                              Dispatch &&d) const {
  VisibilityMaskKHR structResult;
  Result result = static_cast<Result>(d.xrGetVisibilityMaskKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(viewConfigurationType), viewIndex,
      OPENXR_HPP_NAMESPACE::get(visibilityMaskType),
      &(structResult.operator XrVisibilityMaskKHR &())));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getVisibilityMaskKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_WIN32)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertWin32PerformanceCounterToTimeKHR(
    const LARGE_INTEGER *performanceCounter, XrTime *time, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertWin32PerformanceCounterToTimeKHR(
          this->get(), performanceCounter, time));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Time>::type
Instance::convertWin32PerformanceCounterToTimeKHR(
    const LARGE_INTEGER *performanceCounter, Dispatch &&d) const {
  Time structResult;
  Result result =
      static_cast<Result>(d.xrConvertWin32PerformanceCounterToTimeKHR(
          this->get(), performanceCounter, &structResult));
  return impl::createResultValue(
      result, structResult,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::convertWin32PerformanceCounterToTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimeToWin32PerformanceCounterKHR(
    XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertTimeToWin32PerformanceCounterKHR(
          this->get(), time, performanceCounter));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<LARGE_INTEGER>::type
Instance::convertTimeToWin32PerformanceCounterKHR(XrTime time,
                                                  Dispatch &&d) const {
  LARGE_INTEGER structResult;
  Result result =
      static_cast<Result>(d.xrConvertTimeToWin32PerformanceCounterKHR(
          this->get(), time, &structResult));
  return impl::createResultValue(
      result, structResult,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::convertTimeToWin32PerformanceCounterKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimespecTimeToTimeKHR(
    const struct timespec *timespecTime, XrTime *time, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimespecTimeToTimeKHR(this->get(), timespecTime, time));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Time>::type
Instance::convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                                       Dispatch &&d) const {
  Time structResult;
  Result result = static_cast<Result>(d.xrConvertTimespecTimeToTimeKHR(
      this->get(), timespecTime, &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::convertTimespecTimeToTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimeToTimespecTimeKHR(
    XrTime time, struct timespec *timespecTime, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimeToTimespecTimeKHR(this->get(), time, timespecTime));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<timespec>::type
Instance::convertTimeToTimespecTimeKHR(XrTime time, Dispatch &&d) const {
  timespec structResult;
  Result result = static_cast<Result>(
      d.xrConvertTimeToTimespecTimeKHR(this->get(), time, &structResult));
  return impl::createResultValue(result, structResult,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::convertTimeToTimespecTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::perfSettingsSetPerformanceLevelEXT(
    PerfSettingsDomainEXT domain, PerfSettingsLevelEXT level,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPerfSettingsSetPerformanceLevelEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain),
      OPENXR_HPP_NAMESPACE::get(level)));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::perfSettingsSetPerformanceLevelEXT(PerfSettingsDomainEXT domain,
                                            PerfSettingsLevelEXT level,
                                            Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPerfSettingsSetPerformanceLevelEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain),
      OPENXR_HPP_NAMESPACE::get(level)));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Session::perfSettingsSetPerformanceLevelEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::thermalGetTemperatureTrendEXT(
    PerfSettingsDomainEXT domain,
    PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
    float *tempSlope, Dispatch &&d) const {
  XrPerfSettingsNotificationLevelEXT notificationLevel_tmp;
  Result result = static_cast<Result>(d.xrThermalGetTemperatureTrendEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain), notificationLevel_tmp,
      tempHeadroom, tempSlope));
  notificationLevel =
      static_cast<PerfSettingsNotificationLevelEXT>(notificationLevel_tmp);
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::thermalGetTemperatureTrendEXT(
    PerfSettingsDomainEXT domain,
    PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
    float *tempSlope, Dispatch &&d) const {
  XrPerfSettingsNotificationLevelEXT notificationLevel_tmp;
  Result result = static_cast<Result>(d.xrThermalGetTemperatureTrendEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain), notificationLevel_tmp,
      tempHeadroom, tempSlope));
  notificationLevel =
      static_cast<PerfSettingsNotificationLevelEXT>(notificationLevel_tmp);
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::thermalGetTemperatureTrendEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::setDebugUtilsObjectNameEXT(
    const DebugUtilsObjectNameInfoEXT &nameInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetDebugUtilsObjectNameEXT(
      this->get(),
      &(nameInfo.operator const XrDebugUtilsObjectNameInfoEXT &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::setDebugUtilsObjectNameEXT(
    const DebugUtilsObjectNameInfoEXT &nameInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetDebugUtilsObjectNameEXT(
      this->get(),
      &(nameInfo.operator const XrDebugUtilsObjectNameInfoEXT &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::setDebugUtilsObjectNameEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::createDebugUtilsMessengerEXT(
    const DebugUtilsMessengerCreateInfoEXT &createInfo,
    DebugUtilsMessengerEXT &messenger, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateDebugUtilsMessengerEXT(
      this->get(),
      &(createInfo.operator const XrDebugUtilsMessengerCreateInfoEXT &()),
      messenger.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<DebugUtilsMessengerEXT>::type
Instance::createDebugUtilsMessengerEXT(
    const DebugUtilsMessengerCreateInfoEXT &createInfo, Dispatch &&d) const {
  DebugUtilsMessengerEXT handle;
  Result result = static_cast<Result>(d.xrCreateDebugUtilsMessengerEXT(
      this->get(),
      &(createInfo.operator const XrDebugUtilsMessengerCreateInfoEXT &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::createDebugUtilsMessengerEXT");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<DebugUtilsMessengerEXT, impl::RemoveRefConst<Dispatch>>>::type
Instance::createDebugUtilsMessengerUniqueEXT(
    const DebugUtilsMessengerCreateInfoEXT &createInfo, Dispatch &&d) const {
  DebugUtilsMessengerEXT handle;
  Result result = static_cast<Result>(d.xrCreateDebugUtilsMessengerEXT(
      this->get(),
      &(createInfo.operator const XrDebugUtilsMessengerCreateInfoEXT &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<DebugUtilsMessengerEXT,
                                 impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::createDebugUtilsMessengerUniqueEXT");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result DebugUtilsMessengerEXT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroyDebugUtilsMessengerEXT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
DebugUtilsMessengerEXT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroyDebugUtilsMessengerEXT(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::DebugUtilsMessengerEXT::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::submitDebugUtilsMessageEXT(
    XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT messageTypes,
    const DebugUtilsMessengerCallbackDataEXT &callbackData,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSubmitDebugUtilsMessageEXT(
      this->get(), messageSeverity, messageTypes,
      &(callbackData.operator const XrDebugUtilsMessengerCallbackDataEXT &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::submitDebugUtilsMessageEXT(
    XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT messageTypes,
    const DebugUtilsMessengerCallbackDataEXT &callbackData,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSubmitDebugUtilsMessageEXT(
      this->get(), messageSeverity, messageTypes,
      &(callbackData.operator const XrDebugUtilsMessengerCallbackDataEXT &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::submitDebugUtilsMessageEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionBeginDebugUtilsLabelRegionEXT(
    const DebugUtilsLabelEXT &labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSessionBeginDebugUtilsLabelRegionEXT(
      this->get(), &(labelInfo.operator const XrDebugUtilsLabelEXT &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::sessionBeginDebugUtilsLabelRegionEXT(
    const DebugUtilsLabelEXT &labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSessionBeginDebugUtilsLabelRegionEXT(
      this->get(), &(labelInfo.operator const XrDebugUtilsLabelEXT &())));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Session::sessionBeginDebugUtilsLabelRegionEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrSessionEndDebugUtilsLabelRegionEXT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrSessionEndDebugUtilsLabelRegionEXT(this->get()));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Session::sessionEndDebugUtilsLabelRegionEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionInsertDebugUtilsLabelEXT(
    const DebugUtilsLabelEXT &labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSessionInsertDebugUtilsLabelEXT(
      this->get(), &(labelInfo.operator const XrDebugUtilsLabelEXT &())));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::sessionInsertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo,
                                         Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSessionInsertDebugUtilsLabelEXT(
      this->get(), &(labelInfo.operator const XrDebugUtilsLabelEXT &())));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::sessionInsertDebugUtilsLabelEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSpatialAnchorMSFT(
    const SpatialAnchorCreateInfoMSFT &createInfo, SpatialAnchorMSFT &anchor,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorCreateInfoMSFT &()),
      anchor.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<SpatialAnchorMSFT>::type
Session::createSpatialAnchorMSFT(const SpatialAnchorCreateInfoMSFT &createInfo,
                                 Dispatch &&d) const {
  SpatialAnchorMSFT handle;
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorCreateInfoMSFT &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSpatialAnchorMSFT");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<SpatialAnchorMSFT, impl::RemoveRefConst<Dispatch>>>::type
Session::createSpatialAnchorUniqueMSFT(
    const SpatialAnchorCreateInfoMSFT &createInfo, Dispatch &&d) const {
  SpatialAnchorMSFT handle;
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorCreateInfoMSFT &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<SpatialAnchorMSFT,
                                 impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createSpatialAnchorUniqueMSFT");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSpatialAnchorSpaceMSFT(
    const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Space &space,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorSpaceMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorSpaceCreateInfoMSFT &()),
      space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Space>::type
Session::createSpatialAnchorSpaceMSFT(
    const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorSpaceMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorSpaceCreateInfoMSFT &()),
      handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSpatialAnchorSpaceMSFT");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>::type
Session::createSpatialAnchorSpaceUniqueMSFT(
    const SpatialAnchorSpaceCreateInfoMSFT &createInfo, Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(d.xrCreateSpatialAnchorSpaceMSFT(
      this->get(),
      &(createInfo.operator const XrSpatialAnchorSpaceCreateInfoMSFT &()),
      handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::createSpatialAnchorSpaceUniqueMSFT");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result SpatialAnchorMSFT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroySpatialAnchorMSFT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
SpatialAnchorMSFT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroySpatialAnchorMSFT(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::SpatialAnchorMSFT::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

} // namespace OPENXR_HPP_NAMESPACE

#endif
