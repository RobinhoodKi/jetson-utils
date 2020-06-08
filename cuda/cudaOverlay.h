/*
 * Copyright (c) 2017, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __CUDA_OVERLAY_H__
#define __CUDA_OVERLAY_H__


#include "cudaUtility.h"
#include "imageFormat.h"


/**
 * cudaRectFill
 * @ingroup cuda
 */
cudaError_t cudaRectFill( void* input, void* output, imageFormat format, 
					 uint32_t width, uint32_t height, 
					 float4* rects, int numRects, 
					 const float4& color );

/**
 * cudaRectFill
 * @ingroup cuda
 */
template<typename T> cudaError_t cudaRectFill( T* input, T* output, 
				 					  uint32_t width, uint32_t height, 
				 					  float4* rects, int numRects, 
				 					  const float4& color )	
{ 
	return cudaRectFill(input, output, imageFormatFromType<T>(), width, height, rects, numRects, color); 
}

/**
 * cudaRectOutline
 * @ingroup cuda
 */
//cudaError_t cudaRectOutline( float4* input, float4* output, uint32_t width, uint32_t height, float4* boundingBoxes, int numBoxes, const float4& color );


#endif
