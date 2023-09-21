
#include <maxmod9.h>
#include <stdio.h>
#include <time.h>

#include <nds.h>
#include <filesystem.h>

#include <nf_lib.h>
#include "soundbank.h"
u32 startTime;
s16 currentRoom = 0; // Variable para llevar un seguimiento de la sala actual

	mm_sound_effect start = {  
            	{ SFX_START } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning 
		};  

	mm_sound_effect cursor = {
            	{ SFX_CURSOR } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning 
		};  
		
void changeRoom(int newRoom) {
    // Lógica para cargar y configurar los fondos de la nueva sala
    
          mmLoadEffect( SFX_INTRO ); 
            mmLoadEffect( SFX_CURSOR ); 
               mmLoadEffect( SFX_START ); 
            mm_sound_effect intro = {
            	{ SFX_INTRO } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning 
		};
	
    switch (newRoom) { 
        case 0:
            // Cargar y configurar los fondos para la sala 0
            // Ejemplo:
            NF_CreateTextLayer(0,1,0,"outline");  
            NF_CreateTextLayer(1,0,0,"outline");  
            NF_LoadSpriteGfx("sprite/masher",0,32,32);
            NF_LoadSpritePal("sprite/masher",0);
            NF_Vram3dSpriteGfx(0, 0,false);
            NF_Vram3dSpritePal(0, 0);
            NF_Create3dSprite(0, 0, 0,112,80);
            mmEffectEx(&intro); 
			NF_WriteText(0,1, 12, 15, "masherzn"); 
            break;
        case 1:
            // Cargar y configurar los fondos para la sala 1
            // Ejemplo:
         ;
           
            NF_Free3dSpriteGfx(0);
            NF_Delete3dSprite(0);
            NF_LoadTiledBg("bg/tittle_bglast", "bglast", 256, 256); 
            NF_LoadTiledBg("bg/tittle_name", "logo", 256, 256); 
            NF_LoadTiledBg("bg/tittle_move", "move", 256, 256); 
            NF_LoadTiledBg("bg/tittleb_bg", "dbg", 256, 256);
			NF_LoadTiledBg("bg/tittleb_press", "press", 256, 256);  
			NF_LoadSpriteGfx("sprite/tittle_fade",9, 64, 64);
			NF_LoadSpritePal("sprite/tittle_fade",9);
            NF_CreateTiledBg(0, 3, "bglast");
            NF_CreateTiledBg(0, 2, "logo");
            NF_CreateTiledBg(0, 1, "move");
            NF_CreateTiledBg(1, 2, "dbg");
            NF_CreateTiledBg(1, 1, "press");
            NF_Vram3dSpriteGfx(9, 9, true);
            NF_Vram3dSpritePal(9, 9);
            NF_Create3dSprite(9, 9, 9, 96, 64);
            NF_Scale3dSprite(9,0,0);
            
            
        
            break;
             case 2:
            // Cargar y configurar los fondos para la sala 2
            
            
            NF_UnloadTiledBg("dbg");
            NF_UnloadTiledBg("press");
            NF_UnloadTiledBg("bglast");
            NF_UnloadTiledBg("logo");
            NF_UnloadTiledBg("move");
            
        
            NF_LoadTiledBg("bg/bg_black", "black", 256, 256); 
            NF_LoadTiledBg("bg/menu_bglast", "menulast", 256, 256); 
            NF_LoadTiledBg("bg/menu_bg1", "menubg1", 256, 256); 
            NF_LoadTiledBg("bg/menu_bg2", "menubg2", 256, 256); 
            NF_CreateTiledBg(0, 3, "menulast");
            NF_CreateTiledBg(0, 2, "menubg1");
			NF_CreateTiledBg(0,1, "menubg2");
			//NF_CreateTiledBg(0,1, "black");
           
            NF_LoadSpriteGfx("sprite/menu_group1", 1, 64, 64);
            NF_LoadSpriteGfx("sprite/menu_group2", 2, 64, 64);
            NF_LoadSpriteGfx("sprite/menu_solo1",3, 64, 64);
            NF_LoadSpriteGfx("sprite/menu_solo2",4, 64, 64);
            NF_LoadSpriteGfx("sprite/menu_locked",5, 64, 64);
            NF_LoadSpriteGfx("sprite/menu_vault",6,64, 64);
            NF_LoadSpriteGfx("sprite/menu_options",7,64, 64);
            NF_LoadSpriteGfx("sprite/menu_data",8,64, 64);
          
            NF_LoadSpritePal("sprite/menu_group1", 1);
            NF_LoadSpritePal("sprite/menu_group2", 2);
            NF_LoadSpritePal("sprite/menu_solo1",3);
            NF_LoadSpritePal("sprite/menu_solo2",4);
            NF_LoadSpritePal("sprite/menu_locked",5);
            NF_LoadSpritePal("sprite/menu_vault",6);
            NF_LoadSpritePal("sprite/menu_options",7);
            NF_LoadSpritePal("sprite/menu_data",8);
            
              
            NF_Vram3dSpriteGfx(1, 1, true);
            NF_Vram3dSpritePal(1, 1);
           
            NF_Vram3dSpriteGfx(2, 2, true);
            NF_Vram3dSpritePal(2, 2);
           
            NF_Vram3dSpriteGfx(3, 3, true);
            NF_Vram3dSpritePal(3, 3);
            
            NF_Vram3dSpriteGfx(4, 4, true);
            NF_Vram3dSpritePal(4, 4);
           
            NF_Vram3dSpriteGfx(5, 5, true);
            NF_Vram3dSpritePal(5, 5);
            
            NF_Vram3dSpriteGfx(6, 6, true);
            NF_Vram3dSpritePal(6, 6);
           
            NF_Vram3dSpriteGfx(7, 7, true);
            NF_Vram3dSpritePal(7, 7);
            
            NF_Vram3dSpriteGfx(8, 8, true);
            NF_Vram3dSpritePal(8, 8);
            
          
            NF_Create3dSprite(1, 1, 1, 13, 28);
            NF_Create3dSprite(2, 2, 2, 76, 28);
            NF_Create3dSprite(3, 3, 3, 123, 47);
            NF_Create3dSprite(4, 4, 4, 187, 47);
            NF_Create3dSprite(5, 5, 5, 14, 94);
            NF_Create3dSprite(6, 6, 6, 77, 99);        
            NF_Create3dSprite(7, 7, 7, 130, 99);
            NF_Create3dSprite(8, 8, 8, 183, 99);
           
        
           
            
            mmLoad( MOD_MENU1 );
            mmStart( MOD_MENU1, MM_PLAY_LOOP );
            NF_Free3dSpriteGfx(9);
            NF_Delete3dSprite(9);
            
            break;
        // Agregar más casos para cada sala adicional
        
        default:
            // Sala no válida, maneja el caso según sea necesario
            break;
    }
    
    currentRoom = newRoom; // Actualizar la sala actual
   
     NF_Sort3dSprites();
     }


int main(int argc, char **argv) {
    // Inicializar Nintendo DS
    consoleDemoInit();
     
     srand(time(NULL));

    // Prepare a NitroFS initialization screen
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    
    NF_Set3D(0, 0);
    NF_Set2D(1, 0);
    
    consoleDemoInit();
    startTime = clock();
    printf("\n    Loading...");
    swiWaitForVBlank();
    NF_Update3dSpritesGfx();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");
    mmInitDefault( "nitro:/soundbank.bin" );
    
    
   
    // Initialize tiled backgrounds system
    
    NF_InitTiledBgBuffers();    // Initialize storage buffers
    NF_InitTiledBgSys(0);       // Top screen
    NF_InitTiledBgSys(1);       // Bottom screen
    
    NF_InitTextSys(0); 
    NF_LoadTextFont("fnt/fontout","outline", 256,256,0);
     NF_InitSpriteBuffers();     // Initialize storage buffers
     NF_Init3dSpriteSys();
    char segundos[200];
    s16 bgX = 0;
    s16 fadeX = 0;
    s16 fadeY = 0;
    s16 titlestate =0;
    s16 seconds=0;
    //indican donde comienza la posicion de las barras del menu principal
    s16 mbgsY=-4;
    s16 mbgsY2=4;
    //main menu button hover variable
    
    //menu animations
    s16 btn_frame = 0;
    s16 btn_anim = 0;
    s16 btn_anid =0;
   
    mmLoad( MOD_MENU1 );
    // Configurar la primera sala al iniciar el juego
    changeRoom(0);
     NF_Sort3dSprites();
    consoleClear();
   
    

     //mmStart( MOD_MENU1, MM_PLAY_LOOP );
    while (1) { 
    	 NF_UpdateTextLayers();
     swiWaitForVBlank(); 
     snprintf(segundos, sizeof(segundos), "Segundos: %d %d %d %d ", seconds,btn_anid,currentRoom,mbgsY2);
     
            NF_WriteText(1, 0, 1, 1, segundos);
    
       btn_anim++;
        if (btn_anim >0.5 && btn_anid==0 && currentRoom>=2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 7)
                btn_frame = 7;
            NF_Set3dSpriteFrame(1,btn_frame);
            NF_Set3dSpriteFrame(2,btn_frame);
        } 
         if (btn_anim >0.5 && btn_anid==1 && currentRoom>=2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 8)
                btn_frame = 8;
            NF_Set3dSpriteFrame(3,btn_frame);
            NF_Set3dSpriteFrame(4,btn_frame);
        } 
        
        
        
        
        if(currentRoom==0){
        	
      
        seconds+= 1;
         // Mover el fondo 1 píxel a la izquierda
        
    
    	   
		}
		
		
          	 if (seconds==50 && currentRoom==0) {
           changeRoom(currentRoom+1);

     
     	}
     
        if(currentRoom==1){
        	
        bgX += 1; // Mover el fondo 1 píxel a la derecha
        fadeX+= 1;
        fadeY+= 1;
        seconds+= 1;
       
         // Mover el fondo 1 píxel a la izquierda
        
    	  NF_ScrollBg(0,1, bgX,0);  
		}
			 if (currentRoom==2) {
		   mbgsY+=1;
		   mbgsY2-=1;
           NF_ScrollBg(0,1,0,mbgsY);  
           NF_ScrollBg(0,2,0,mbgsY2);  
          
         }     
            
	
	
    	   scanKeys(); 
        // Ejemplo: Cambiar a la sala 1 cuando se presione un botón
        if (keysDown() & KEY_UP) {
             mmEffectEx(&cursor); 
        }    
		
		 if (keysDown() & KEY_DOWN) {
             mmEffectEx(&cursor); 
        }     
        
		 if (keysDown() & KEY_RIGHT && currentRoom==2) {
             mmEffectEx(&cursor); 
             btn_frame=0;
             btn_anid++;
        }  
		  
        
		 if (keysDown() & KEY_LEFT && currentRoom==2) {
             mmEffectEx(&cursor); 
            btn_frame=0;
             btn_anid--;
        }     
         
         	 if (keysDown() & KEY_START && currentRoom==1 && titlestate==0) {
         	seconds=0; 	
         	fadeX= 0;
            fadeY= 0;
            titlestate=1;
            mmEffectEx(&start); 
            

        }     
          	 if (titlestate==1 && currentRoom==1) {
            NF_Scale3dSprite(9,fadeX*30,fadeY*30);

        }     
         
          	 if (seconds==30 && titlestate==1) {
           changeRoom(currentRoom=2); 
           seconds=0;
          
        }     
        	 if (btn_anid!=0 && currentRoom==2) {
            NF_Set3dSpriteFrame(1,0);
            NF_Set3dSpriteFrame(2,0);
         }    
		 	 if (btn_anid!=1 && currentRoom==2) {
            NF_Set3dSpriteFrame(3,0);
            NF_Set3dSpriteFrame(4,0);
         }     
         	 if (mbgsY>=0 && currentRoom==2) {
            
            mbgsY=0;  
             }
              if (mbgsY2<=1 && currentRoom==2) {
            
            mbgsY2=1;  
			
             }
            
            
            
           

         
        
         
        
        if (keysDown() & KEY_A) {
            //changeRoom(currentRoom+1);
        }     
       /* if (keysDown() & KEY_B) {
            changeRoom(currentRoom-1);
        }
         if (keysDown() & KEY_START && currentRoom==1) {
             
        }
       */   NF_Draw3dSprites();
        // Tell the GPU to draw the scene and wait until it's done
        glFlush(0);
        // Obtener el tiempo actual en milisegundos
       swiWaitForVBlank();
        NF_Update3dSpritesGfx();
    }
    
    return 0;
}
