// Copyright 2019 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "common/common_types.h"
#include "video_core/dirty_flags.h"
#include "video_core/engines/maxwell_3d.h"

namespace Core {
class System;
}

namespace OpenGL {

namespace Dirty {
enum : u8 {
    First = VideoCommon::Dirty::LastCommonEntry,

    VertexFormats,
    VertexBuffers,
    VertexInstances,
    Shaders,
    Viewports,
    CullTestEnable,
    FrontFace,
    CullFace,
    PrimitiveRestart,
    DepthTest,
    StencilTest,
    ColorMask,
    BlendState,
    PolygonOffset,

    VertexBuffer0 = PolygonOffset + 8,
    VertexInstance0 = VertexBuffer0 + 32,
};
}

class StateTracker {
public:
    explicit StateTracker(Core::System& system);

    void Initialize();

    void NotifyFramebuffer() {
        auto& flags = system.GPU().Maxwell3D().dirty.flags;
        flags[VideoCommon::Dirty::RenderTargets] = true;
    }

private:
    Core::System& system;
};

} // namespace OpenGL
