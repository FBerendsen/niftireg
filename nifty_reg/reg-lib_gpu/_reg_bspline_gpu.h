/*
 *  _reg_bspline_gpu.h
 *  
 *
 *  Created by Marc Modat on 24/03/2009.
 *  Copyright (c) 2009, University College London. All rights reserved.
 *  Centre for Medical Image Computing (CMIC)
 *  See the LICENSE.txt file in the nifty_reg root folder
 *
 */

#ifndef _REG_BSPLINE_GPU_H
#define _REG_BSPLINE_GPU_H

#include "_reg_blocksize_gpu.h"

extern "C++"
void reg_bspline_gpu(   nifti_image *controlPointImage,
                        nifti_image *targetImage,
                        float4 **controlPointImageArray_d,
                        float4 **positionFieldImageArray_d,
                        int **mask,
                        int activeVoxelNumber);

extern "C++"
float reg_bspline_ApproxBendingEnergy_gpu(	nifti_image *controlPointImage,
                                            float4 **controlPointImageArray_d);

extern "C++"
float reg_bspline_ComputeJacobianPenaltyTerm_gpu(   nifti_image *targetImage,
                                                    nifti_image *controlPointImage,
                                                    float4 **controlPointImageArray_d,
                                                    bool approximate);

extern "C++"
void reg_bspline_ApproxBendingEnergyGradient_gpu(   nifti_image *targetImage,
                                                    nifti_image *controlPointImage,
							                        float4 **controlPointImageArray_d,
							                        float4 **nodeNMIGradientArray_d,
							                        float bendingEnergyWeight);

extern "C++"
void reg_bspline_ComputeJacobianGradient_gpu(   nifti_image *targetImage,
                                                nifti_image *controlPointImage,
                                                float4 **controlPointImageArray_d,
                                                float4 **nodeNMIGradientArray_d,
                                                float jacobianWeight,
                                                bool appJacobianFlag);

extern "C++"
float reg_bspline_correctFolding_gpu(   nifti_image *targetImage,
                                        nifti_image *controlPointImage,
                                        float4 **controlPointImageArray_d,
                                        bool approx);

extern "C++"
void reg_spline_cppComposition_gpu( nifti_image *toUpdate,
                                    nifti_image *toCompose,
                                    float4 **toUpdateArray_d,
                                    float4 **toComposeArray_d,
                                    float ratio,
                                    bool type);

#endif