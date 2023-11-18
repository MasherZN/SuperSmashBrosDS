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
    NF_Update3dSpritesGfx();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");
    mmInitDefault( "nitro:/soundbank.bin" );
    NF_Set3D(0, 0);
    NF_Set2D(1, 0);
    
    // Initialize tiled backgrounds system
    NF_InitTiledBgBuffers();    // Initialize storage buffers
    NF_InitTiledBgSys(0);       // Top screen
    NF_InitTiledBgSys(1);       // Bottom screen

    // Initialize sprite system
    NF_InitSpriteBuffers();     // Initialize storage buffers
    NF_Init3dSpriteSys();
    
   	// load the module
	mmLoad( MOD_MENU1 );
	mmLoadEffect( SFX_FFA );
	mm_sound_effect ffa = {
		{ SFX_FFA } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
		};
    /*mmLoadEffect( SFX_SHON );
    mmLoadEffect( SFX_MARTAUNT );
    mmLoadEffect( SFX_SEMARTAUNT );
      mmLoadEffect( SFX_MARENTRY );
    
     mm_sound_effect semartaunt = {
		{ SFX_SEMARTAUNT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
	};
	
     mm_sound_effect martaunt = {
		{ SFX_MARTAUNT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
	};
    
    mm_sound_effect shon = {
		{ SFX_SHON } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
	};
	
	 mm_sound_effect entry = {
		{ SFX_MARENTRY } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
	};
	// Start playing module
*/	
 
    // Initialize 2D engine in both screens and use mode 0
    

    
   /* NF_LoadTiledBg("bg/bgdreamland", "capa_3", 256, 256);
    NF_LoadTiledBg("bg/bg2", "capa_2", 512, 512);
    NF_LoadTiledBg("bg/css", "css_1", 256, 256);
    NF_LoadTiledBg("bg/bfbg", "bfbg", 256, 256);
    NF_LoadTiledBg("bg/bfstage", "bfds", 512, 512);
    // Load sprite files from NitroFS
    NF_LoadSpriteGfx("sprite/personaje", 0, 64, 64);
    NF_LoadSpritePal("sprite/personaje", 0);
    NF_LoadSpriteGfx("sprite/p1show", 1, 64, 64);
    NF_LoadSpritePal("sprite/p1show", 1);
    NF_LoadSpriteGfx("sprite/shield", 2, 64, 64);
    NF_LoadSpritePal("sprite/shield", 2);
    NF_LoadSpriteGfx("sprite/grab", 3, 64, 64);
    NF_LoadSpritePal("sprite/grab", 3);
    NF_LoadSpriteGfx("sprite/taunt", 4, 64, 64);
    NF_LoadSpritePal("sprite/taunt", 4);
    NF_LoadSpriteGfx("sprite/walk", 5, 64, 64);
    NF_LoadSpritePal("sprite/walk", 5);
    NF_LoadSpriteGfx("sprite/entrance", 6, 64, 64);
    NF_LoadSpritePal("sprite/entrance", 6);
   // NF_LoadSpriteGfx("sprite/sandbag", 7, 64, 64);
   // NF_LoadSpritePal("sprite/sandbag", 7);
    NF_LoadSpriteGfx("sprite/mario_crouch", 8, 64, 64);
    NF_LoadSpritePal("sprite/mario_crouch", 8);
    */

     
     
    s16 handx = 0; 
    s16 handy = 0; 
    s16 hstate = 0;
    mmStart( MOD_MENU1, MM_PLAY_LOOP );
	mmEffectEx(&ffa); 
	
	
 /*
 
    // Create bottom screen backgrounds
    NF_CreateTiledBg(0, 3, "bfbg");
    NF_CreateTiledBg(0, 2, "bfds");
    NF_CreateTiledBg(1, 3, "css_1");

    // Transfer the required sprites to VRAM
    NF_VramSpriteGfx(0, 0, 0, true); // Poniendo los sprites en la VRAM
    NF_VramSpritePal(0, 0, 0);
    NF_VramSpriteGfx(0, 1, 1, true); 
    NF_VramSpritePal(0, 1, 1);
    NF_VramSpriteGfx(0, 2, 2, true); 
    NF_VramSpritePal(0, 2, 2);
    NF_VramSpriteGfx(0, 3, 3, true); 
    NF_VramSpritePal(0, 3, 3);  
    NF_VramSpriteGfx(0, 4, 4, true); 
    NF_VramSpritePal(0, 4, 4);  
    NF_VramSpriteGfx(0, 5, 5, true); 
    NF_VramSpritePal(0, 5, 5);  
    NF_VramSpriteGfx(0, 6, 6, true); 
    NF_VramSpritePal(0, 6, 6); 
	//NF_VramSpriteGfx(0, 7, 7, true); 
   // NF_VramSpritePal(0, 7, 7);  
    NF_VramSpriteGfx(0, 8, 8, true); 
    NF_VramSpritePal(0, 8, 8); 
    NF_CreateSprite(0, 1, 1, 1, 100, 92);
   
    //NF_CreateSprite(0, 7, 7, 7, 100,100);
    NF_SpriteLayer(0, 0, 1);
    
    // Setup character sprite
    s16 x = 120;
    s16 y = 286;
    s16 pj_frame = 0;
    s16 pj_anim = 0;
    s16 spr_x = 0;
    s16 spr_y = 0;
    s16 bg_x = 1;
    s16 bg_y = 1;
    s16 pj_anid =5;
    s16 dir = 1;
    
     if (pj_anid==5 && pj_frame>=0)  {
        mmEffectEx(&entry);
        }
    

   */
    NF_Sort3dSprites();
   while (1)
    {
    	   scanKeys(); // Read keypad
        u16 keys = keysHeld(); // Keys currently pressed

            if (keys & KEY_UP)
            handy --;
            if (keys & KEY_DOWN)
            handy ++;
            if (keys & KEY_LEFT)
            handx --;
            if (keys & KEY_RIGHT)
            handx ++;
            
            NF_Move3dSprite(0, handx*2.5, handy*2.5);
            NF_Set3dSpritePriority(0,0);
            
        if (keysDown() & KEY_A && hstate ==0) {
        	hstate =1;
        	NF_Create3dSprite(31, 31, 31,158,141);
        	NF_Create3dSprite(1, 1, 1,handx*2.5, handy*2.5);
            NF_Delete3dSprite(2);
            NF_Delete3dSprite(0);
            
            
        	}
        	if (hstate ==1) {
        	
        	
        	
        	NF_Set3dSpritePriority(1,0);
        	NF_Move3dSprite(1, handx*2.5, handy*2.5);
        
        	
        	}
        	if (keysDown() & KEY_B && hstate ==1) {
        	 hstate =0;
        	NF_Delete3dSprite(1);
        	NF_Create3dSprite(2, 2, 2, handx*2.5, handy*2.5);
            NF_Create3dSprite(0, 0, 0,handx*2.5, handy*2.5);
            
            NF_Set3dSpritePriority(2,0);
            NF_Set3dSpritePriority(1,0);
            NF_Set3dSpritePriority(0,0);
            
            
          
        	}
        	
        		
        	
        	
        /* 
        // Animate character
        pj_anim++;
        if (pj_anim >5 && pj_anid==0)
        {
            pj_anim = 0;
            pj_frame ++;
            
            if (pj_frame > 7)
                pj_frame = 0;
            NF_SpriteFrame(0, 0, pj_frame);
        } 
           if (pj_anim >3 && pj_anid==1)
        {
        	
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame >7)
                pj_frame = 0;
            NF_SpriteFrame(0, 3, pj_frame);
            } 
            
               if (pj_anim >3 && pj_anid==3)
        {
        	
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame >13)
                pj_frame = 0;
            NF_SpriteFrame(0, 4, pj_frame);
            } 
            if (pj_anim >4 && pj_anid==4)
        {
        	
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame >7)
                pj_frame = 0;
            NF_SpriteFrame(0, 5, pj_frame);
            } 
            
            if (pj_anim >5 && pj_anid==5)
        {
        	
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame >11)
                pj_frame = 0;
            NF_SpriteFrame(0, 6, pj_frame);
            } 
            
            
            
            if (pj_anim >6 && pj_anid==7)
             {
        	
            pj_anim = 0;
            pj_frame ++;
            if (pj_frame >1)
                pj_frame = 1;
            NF_SpriteFrame(0, 8, pj_frame);
            } 
         
         
            
          if (dir == -1){
          		NF_HflipSprite(0, 0, true);
          	
          	NF_HflipSprite(0, 2, true);
          	NF_HflipSprite(0, 3, true);
          	NF_HflipSprite(0, 4, true);
          	NF_HflipSprite(0, 5, true);
          	NF_HflipSprite(0, 6, true);
          	NF_HflipSprite(0, 8, true);
         
          	
          	}
          	if (dir == 1){
          	 
        NF_HflipSprite(0, 0, false);
          	
          	NF_HflipSprite(0, 2, false);
          	NF_HflipSprite(0, 3, false);
          	NF_HflipSprite(0, 4, false);
          	NF_HflipSprite(0, 5, false);
          	NF_HflipSprite(0, 8, false);
          	}
         
         
      
        
    
        
      

      
        	
		}
            
            
            
           //shield ctr
          if (keysDown() & KEY_R && pj_anid ==0)  {
          	NF_DeleteSprite(0, 0);
            pj_anid=2;
        NF_CreateSprite(0, 2, 2, 2, 100, 92);
        mmEffectEx(&shon);
        }
         //shield grab ctrl
         if (keysDown() & KEY_A && pj_anid ==2)  {
          	NF_DeleteSprite(0, 2);
          	NF_CreateSprite(0, 3, 3, 3, 100, 92);
            pj_anid=1;
            pj_frame = 0;
        pj_anim = 0;
        
        
        }
            //shield up ctrl
        if (keysUp() & KEY_R && pj_anid ==2)  {
        NF_DeleteSprite(0, 2);
        NF_CreateSprite(0, 0, 0, 0, 100, 92);
        pj_anid=0;
        pj_anim = 0;
        
        }
         //grab ctrl
        if (keysDown() & KEY_L && pj_anid==0)  {
        NF_DeleteSprite(0, 0);
        NF_CreateSprite(0, 3, 3, 3, 100, 92);
        pj_anid =1;
        pj_frame = 0;
        pj_anim = 0;
        
        
       }
         //grab up ctrl
         if (pj_anid==1 && pj_frame>=7)  {
        NF_DeleteSprite(0, 3);
        NF_CreateSprite(0, 0, 0, 0, 100, 92);
        pj_anid=0;
        pj_frame = 0;
        }
         //shiled grab up ctrl
        if (keysDown() & KEY_R && pj_anid==1 && pj_frame>=7)  {
        NF_DeleteSprite(0, 3);
        NF_CreateSprite(0, 2, 2, 2, 100, 92);
        pj_anid=2;
        pj_frame = 0;
        }
        // taunt controller hold
           if (keysDown() & KEY_SELECT && pj_anid==0)  {
           	mmEffectEx(&martaunt);
           	mmEffectEx(&semartaunt);
        NF_DeleteSprite(0, 0);
        pj_anid =3;
        pj_frame = 0;
        pj_anim = 0;
        NF_CreateSprite(0, 4, 4, 4, 100, 92);
        
       }
        //taunt controller release
           if (pj_anid==3 && pj_frame>=13)  {
        NF_DeleteSprite(0, 4);
        NF_CreateSprite(0, 0, 0, 0, 100, 92);
        pj_anid=0;
        pj_frame = 0;
        }
        
         if (keysDown() & KEY_RIGHT && pj_anid ==0)  {  
         	//walk controller
          	NF_DeleteSprite(0, 0);
            pj_anid=4;
        NF_CreateSprite(0, 5, 5, 5, 100, 92);
          dir =1;
        }
            
               if (keysUp() & KEY_RIGHT && pj_anid ==4)  {
         	//walk controller
          	NF_DeleteSprite(0, 5);
          	

            pj_anid=0;
        NF_CreateSprite(0, 0, 0, 0, 100, 92);
        
        }
        
          if (keysDown() & KEY_LEFT && pj_anid ==0)  {
         	//walk controller
          	    pj_anid=4;
             NF_CreateSprite(0, 5, 5, 5, 100, 92);
              NF_DeleteSprite(0, 0);
              dir =-1;
              	 }
              	 
              	  if (keysUp() & KEY_LEFT && pj_anid ==4)  {
         	//walk left controller
          	   NF_DeleteSprite(0, 5);
          	   NF_CreateSprite(0, 0, 0, 0, 100, 92);
          	     pj_anid=0;
              	 }
              	 
         if (pj_anid==5)  {
        
        NF_CreateSprite(0, 6, 6, 6, 100, 92);
        
         }
        
        //entrance ctrl
        
        
         //entrance ctrl
         if (pj_anid==5 && pj_frame>=11)  {
        NF_DeleteSprite(0, 6);
        NF_CreateSprite(0, 0, 0, 0, 100, 92);
        pj_anid=0;
        pj_frame = 0;
        }
           if (keysDown() & KEY_DOWN && pj_anid ==0)  {
         	//walk controller
          	NF_DeleteSprite(0, 0);
          	pj_frame = 0;
          	NF_CreateSprite(0, 8, 8, 8, 100, 92);
            pj_frame = 0;
            pj_anid=7;
         }      
            if (keysUp() & KEY_DOWN && pj_anid ==7)  {
         	//walk controller
          	NF_DeleteSprite(0, 8);
          	pj_frame = 0;
            NF_CreateSprite(0, 0, 0, 0, 100, 92);
            pj_frame = 0; 
            pj_anid=0;
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
        spr_x = (x - bg_x) - 1;
        spr_y = (y - bg_y) - 1;
        NF_MoveSprite(0, 0, spr_x, spr_y);
        NF_MoveSprite(0, 1, spr_x, spr_y);
        NF_MoveSprite(0, 2, spr_x, spr_y);
        NF_MoveSprite(0,3, spr_x, spr_y);
        NF_MoveSprite(0,4, spr_x, spr_y);
        NF_MoveSprite(0,5, spr_x, spr_y);
       // NF_MoveSprite(0,7, bg_x-10, bg_y+160);
        NF_MoveSprite(0,8, spr_x, spr_y);
          NF_ScrollBg(0, 2, bg_x, bg_y);
        */
        
        
        NF_Draw3dSprites();
        // Tell the GPU to draw the scene and wait until it's done
        glFlush(0);
        // Wait for the screen refresh
        swiWaitForVBlank();
        
        
      }

    return 0;
   }
