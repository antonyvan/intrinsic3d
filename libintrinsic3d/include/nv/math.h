/**
* This file is part of Intrinsic3D.
*
* Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
* Copyright (c) 2019, Technical University of Munich. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*    * Neither the name of NVIDIA CORPORATION nor the names of its
*      contributors may be used to endorse or promote products derived
*      from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <nv/mat.h>
#include <nv/sparse_voxel_grid.h>


/**
 * @brief   Math helper functions
 * @author  Robert Maier <robert.maier@tum.de>
 */
namespace nv
{
namespace math
{

    float robustKernel(float val, float thres = 2.0f);

    bool withinBounds(const Vec6i& bounds, const Vec3i &v_pos);
    bool withinBounds(const Vec6f& bounds, const Vec3i &v_pos);
    bool withinBounds(const Vec6f& bounds, const Vec3f &p);

    template <typename T>
    T average(const float weights[8], const T values[8]);

    void interpolationWeights(const Vec3f& pos, Vec3i coords[8], float weights[8]);

    void computeFrustumPoints(const Camera& cam,
                              const float depth_min, const float depth_max,
                              std::vector<Vec3f> &corner_points);

    Mat4 poseVecAAToMat(const Vec6 &pose_vec_aa);
    Vec6 poseMatToVecAA(const Mat4 &pose);

} // namespace math
} // namespace nv
