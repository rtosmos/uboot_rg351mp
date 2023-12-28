/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef VIDEO_ROCKCHIP_H
#define VIDEO_ROCKCHIP_H

#if defined(CONFIG_PLATFORM_ODROID_GOADV)
	/* set larger fb size to support GO2 & GO3 */
	#define DRM_ROCKCHIP_FB_WIDTH		640
	#define DRM_ROCKCHIP_FB_HEIGHT	480
	#define DRM_ROCKCHIP_FB_BPP		VIDEO_BPP32
#else
	#ifdef CONFIG_DRM_ROCKCHIP_VIDEO_FRAMEBUFFER
		#define DRM_ROCKCHIP_FB_WIDTH		1920
		#define DRM_ROCKCHIP_FB_HEIGHT		1080
		#define DRM_ROCKCHIP_FB_BPP		VIDEO_BPP32
	#else
		#define DRM_ROCKCHIP_FB_WIDTH		0
		#define DRM_ROCKCHIP_FB_HEIGHT		0
		#define DRM_ROCKCHIP_FB_BPP		VIDEO_BPP32
	#endif
#endif

#define MEMORY_POOL_SIZE	32 * 1024 * 1024
#define DRM_ROCKCHIP_FB_SIZE \
	VNBYTES(DRM_ROCKCHIP_FB_BPP) * DRM_ROCKCHIP_FB_WIDTH * DRM_ROCKCHIP_FB_HEIGHT

int rockchip_show_bmp(const char *bmp);
int rockchip_show_logo(void);
void rockchip_display_fixup(void *blob);

#endif
