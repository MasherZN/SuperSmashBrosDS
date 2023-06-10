// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: NightFox & Co., 2009-2011
//
// Sprite loading example
// http://www.nightfoxandco.com
#include <maxmod9.h>
#include <stdio.h>
#include <time.h>

#include <nds.h>
#include <filesystem.h>

#include <nf_lib.h>
#include "soundbank.h"
int main(int argc, char **argv)
{
    // Set random seed based on the current time
    srand(time(NULL));

    // Prepare a NitroFS initialization screen
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    consoleDemoInit();
    printf("\n    Loading...");
    swiWaitForVBlank();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");
    mmInitDefault( "nitro:/soundbank.bin" );
   
   	// load the module
	mmLoad( MOD_BB );

	// Start playing module
	mmStart( MOD_BB, MM_PLAY_LOOP );

    // Initialize 2D engine in both screens and use mode 0
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);

    // Initialize tiled backgrounds system
    NF_InitTiledBgBuffers();    // Initialize storage buffers
    NF_InitTiledBgSys(0);       // Top screen
    NF_InitTiledBgSys(1);       // Bottom screen

    // Initialize sprite system
    NF_InitSpriteBuffers();     // Initialize storage buffers
    NF_InitSpriteSys(0);        // Top screen
    NF_InitSpriteSys(1);        // Bottom screen
    NF_InitTextSys(1);
    
    NF_LoadTiledBg("bg/bgdreamland", "capa_3", 256, 256);
    NF_LoadTiledBg("bg/bg2", "capa_2", 512, 512);
    NF_LoadTiledBg("bg/css", "css_1", 256, 256);

    // Load sprite files from NitroFS
    NF_LoadSpriteGfx("sprite/personaje", 0, 64, 64);
    NF_LoadSpritePal("sprite/personaje", 0);
    NF_LoadSpriteGfx("sprite/shield", 2, 64, 64);
    NF_LoadSpritePal("sprite/shield", 2);
    NF_LoadSpriteGfx("sprite/p1show", 1, 64, 64);
    NF_LoadSpritePal("sprite/p1show", 1);


    // Create bottom screen backgrounds
    NF_CreateTiledBg(0, 3, "capa_3");
    NF_CreateTiledBg(0, 2, "capa_2");
    NF_CreateTiledBg(1, 3, "css_1");

    // Transfer the required sprites to VRAM
    NF_VramSpriteGfx(0, 0, 0, true); // Poniendo los sprites en la VRAM
    NF_VramSpritePal(0, 0, 0);
    NF_VramSpriteGfx(0, 1, 1, true); 
    NF_VramSpritePal(0, 1, 1);
    NF_VramSpriteGfx(0, 2, 2, true); 
    NF_VramSpritePal(0, 2, 2);

    //NF_VramSpriteGfx(0, 1, 0, false); // Character: Keep unused frames in RAM
    //NF_VramSpritePal(0, 1, 0);
    NF_CreateSprite(0, 1, 1, 1, 100, 92);
    NF_CreateSprite(0, 0, 0, 0, 100, 92);
  
    NF_SpriteLayer(0, 0, 1);
    // Setup character sprite
    s16 x = 100;
    s16 y = 96;
    s16 pj_frame = 0;
    s16 pj_anim = 0;
    s16 spr_x = 0;
    s16 spr_y = 0;
    s16 bg_x = 0;
    s16 bg_y = 0;
    NF_LoadTextFont16("fnt/font16", "down", 256, 256, 0);
    NF_CreateTextLayer16(1, 0, 0, "down");
    NF_DefineTextColor(1, 0, 1, 1, 0, 0); // Blanco
    

    while (1)
    {
         
        // Animate character
        pj_anim++;
        if (pj_anim > 5)
        {
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame > 7)
                pj_frame = 0;
            NF_SpriteFrame(0, 0, pj_frame);
        }
        
        scanKeys(); // Read keypad
        u16 keys = keysHeld(); // Keys currently pressed

        if (keys & KEY_UP)
            y --;
        if (keys & KEY_DOWN)
            y ++;
        if (keys & KEY_LEFT)
            x --;
        if (keys & KEY_RIGHT)
            x ++;
            
          if (keysHeld() & KEY_L)  {
       
        NF_CreateSprite(0, 2, 2, 2, 100, 92);
        pj_anim = 1;
        }
            
        if (keysUp() & KEY_L)  {
        
        NF_DeleteSprite(0, 2);
        pj_anim = 0;
        }
        
            
       // Movement limits
        if (x < 0)
            x = 0;
        if (x > 511)
            x = 511;

        if (y < 0)
            y = 0;
        if (y > 768)
            y = 768;

        // Background position
        bg_x = x - 100;
        if (bg_x < 0)
            bg_x = 0;
        if (bg_x > 256)
            bg_x = 256;

        bg_y = y - 95;
        if (bg_y < 0)
            bg_y = 0;
        if (bg_y > 320)
            bg_y = 320;

        // Sprite position
        spr_x = (x - bg_x) - 4;
        spr_y = (y - bg_y) - 4;
        NF_MoveSprite(0, 0, spr_x, spr_y);
        NF_MoveSprite(0, 1, spr_x, spr_y);
        NF_MoveSprite(0, 2, spr_x, spr_y);
        
        NF_WriteText16(1, 0, 10,10, "MARIO");
       

        // Update OAM array
        NF_SpriteOamSet(0);
        NF_SpriteOamSet(1);

        // Wait for the screen refresh
        swiWaitForVBlank();

        // Update OAM
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
        
        NF_ScrollBg(0, 2, bg_x, bg_y);
    }

    return 0;
}
