#define OPENXR_HPP_NO_EXCEPTIONS

#include "xr_dependencies.h"
#include "openxr/openxr.hpp"

static void bla() {
    xr::Instance inst;
    xr::DispatchLoaderDynamic d;
    inst.getVulkanDeviceExtensionsKHR(xr::SystemId{}, d);
}
