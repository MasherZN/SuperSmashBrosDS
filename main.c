  
#include <maxmod9.h>
#include <stdio.h>
#include <time.h>

#include <nds.h>
#include <filesystem.h>
#include <fat.h>
 
#include <nf_lib.h> 
#include "soundbank.h"

#include <unistd.h>

#define MAX_BRIGHTNESS 30   
#define MIN_BRIGHTNESS 0
 

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
		
		
	mm_sound_effect ffa = {
		{ SFX_FFA } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
		};
		
		    
            mm_sound_effect intro = {
            	{ SFX_INTRO } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning 
		};
		
		void fadeToWhite() {
    for (int i = 0; i <= MAX_BRIGHTNESS; i++) {
        setBrightness(i, i);
        swiWaitForVBlank();
        // Agrega un pequeño retraso para que el efecto de fundido sea más suave
        sleep(1);
    }
}
	void fadeToNormal() {
    for (int i = 30; i >= MIN_BRIGHTNESS; i--) {
        setBrightness(i, i);
        swiWaitForVBlank();
        // Agrega un pequeño retraso para que el efecto de fundido sea más suave
       sleep(1);
    }
}
	void createmainmenu(){
		// Cargar y configurar los fondos para la sala 2
            mmLoad( MOD_MENU1 );
            mmStart( MOD_MENU1, MM_PLAY_LOOP );
            NF_ClearTextLayer(0,1); 
            NF_CreateTextLayer(1,0,0,"outline");
            NF_UnloadTiledBg("dbg");
            NF_UnloadTiledBg("bglast");
            NF_UnloadTiledBg("logo");
            NF_UnloadTiledBg("move");
            NF_UnloadTiledBg("press");
            NF_DeleteTiledBg(0,2);
            NF_DeleteTiledBg(0,3);
            NF_DeleteTiledBg(1,1);
            NF_DeleteTiledBg(1,2);
            NF_DeleteTiledBg(0,1);
            NF_Delete3dSprite(9);
            
             
           
            NF_LoadTiledBg("bg/menu_bglast", "menulast", 256, 256); 
            NF_LoadTiledBg("bg/menu_bg1", "menubg1", 256, 256); 
            NF_LoadTiledBg("bg/menu_bg2", "menubg2", 256, 256); 
            NF_LoadTiledBg("bg/mode_smash", "modesmash", 256, 256); 
            NF_LoadTiledBg("bg/modebg", "modobg", 256, 256); 
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
             
           	NF_CreateTiledBg(1,2, "modesmash");
			NF_CreateTiledBg(1,3, "modobg");
            NF_Create3dSprite(1, 1, 1, 12, 28);
            NF_Create3dSprite(2, 2, 2, 76, 28);
            NF_Create3dSprite(3, 3, 3, 123, 47); 
            NF_Create3dSprite(4, 4, 4, 187, 47);
            NF_Create3dSprite(5, 5, 5, 14, 94);
            NF_Create3dSprite(6, 6, 6, 77, 99);        
            NF_Create3dSprite(7, 7, 7, 130, 99);
            NF_Create3dSprite(8, 8, 8, 183, 99);
		
	}
	void borrarmenu(){
			
	
			                                    	
	NF_UnloadSpriteGfx(0);
	NF_UnloadSpritePal(0);
	NF_Free3dSpriteGfx(0);
		 
	NF_UnloadSpriteGfx(1);
	NF_UnloadSpritePal(1);
	NF_Free3dSpriteGfx(1);
		  	 
	NF_UnloadSpriteGfx(2);
	NF_UnloadSpritePal(2);
	NF_Free3dSpriteGfx(2);
		  	  	 
	NF_UnloadSpriteGfx(3);
	NF_UnloadSpritePal(3);
	NF_Free3dSpriteGfx(3);
		  	  	  	 
	NF_UnloadSpriteGfx(4);
	NF_UnloadSpritePal(4);
	NF_Free3dSpriteGfx(4);
		  	  	  	  	
	NF_UnloadSpriteGfx(5);
	NF_UnloadSpritePal(5);
	NF_Free3dSpriteGfx(5);
		  	  	  	  	  	  
	NF_UnloadSpriteGfx(6);
	NF_UnloadSpritePal(6);
	NF_Free3dSpriteGfx(6);
		  	  	  	  	  	  	 
	NF_UnloadSpriteGfx(7);
	NF_UnloadSpritePal(7);
	NF_Free3dSpriteGfx(7);
		  	  	  	  	  	  	  	  
	NF_UnloadSpriteGfx(8);
	NF_UnloadSpritePal(8);
	NF_Free3dSpriteGfx(8);
		  	  	  	  	  	  	  	  	 
	NF_UnloadSpriteGfx(9);
	NF_UnloadSpritePal(9);
	NF_Free3dSpriteGfx(9);
		  	  	  	  	  	  	  	  	  
	NF_Delete3dSprite(1);
	NF_Delete3dSprite(2);
	NF_Delete3dSprite(3); 
	NF_Delete3dSprite(4);
	NF_Delete3dSprite(5);
	NF_Delete3dSprite(6);
	NF_Delete3dSprite(7);
	NF_Delete3dSprite(8);
		  	  	  	  	  	  	  	  	  
        
           
		}
	
void changeRoom(int newRoom) {
    // Lógica para cargar y configurar los fondos de la nueva sala
    
    
		
	
    switch (newRoom) { 
        case 0:
            // Cargar y configurar los fondos para la sala 0
            // Ejemplo:
              mmLoadEffect( SFX_INTRO ); 
            mmLoadEffect( SFX_CURSOR ); 
               mmLoadEffect( SFX_START ); 
               mmLoadEffect( SFX_FFA ); 
            NF_CreateTextLayer(0,1,0,"outline");     
            NF_LoadSpriteGfx("sprite/masher",0,32,32);
            NF_LoadSpritePal("sprite/masher",0);
            NF_Vram3dSpriteGfx(0, 0,false);
            NF_Vram3dSpritePal(0, 0);
            NF_Create3dSprite(0, 0, 0,112,80);
            mmEffectEx(&intro); 
			NF_WriteText(0,1, 12, 15, "MasherZN"); 
			
            break;
        case 1:
            // Cargar y configurar los fondos para la sala 1
            // Ejemplo:
         
           
            
            NF_Delete3dSprite(0);
            
            NF_ClearTextLayer(0,1); 
            
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
            NF_CreateTextLayer(1,0,0,"outline");
            NF_WriteText(1,0, 9, 0, "@2023 MasherZN         Original Game:@Nintendo/HAL Lab Characters: @Nintendo / HAL lab /Pokemon/Creatures Inc/GAMEFREAK");  
            
            
        
            break;
             case 2:
            lcdMainOnBottom();
            createmainmenu();
            
             sleep(5);
            
            
          
            setBrightness(-1,-1);	
            
            
        
           
           
            
            
           
            
            break;
        // Agregar más casos para cada sala adicional
         case 3:
         	
         
         
      
         
    NF_UnloadTiledBg("menulast");
	NF_UnloadTiledBg("menubg2");
    NF_UnloadTiledBg("menubg1");
    NF_UnloadTiledBg("modobg");
    NF_UnloadTiledBg("modesmash");
    NF_DeleteTiledBg(0,3);
    NF_DeleteTiledBg(0,2);
    NF_DeleteTiledBg(0,1);
    NF_DeleteTiledBg(1,2);
    NF_DeleteTiledBg(1,3);
	     
    NF_LoadTiledBg("bg/css_backgroundtop", "backgroundt", 256, 256);
    NF_LoadTiledBg("bg/css_backgroundbottom", "backgroundb", 256, 256);
    NF_LoadTiledBg("bg/css_backgroundbottom2", "backgroundb2", 256, 256);
    NF_LoadTiledBg("bg/css_backgroundbottom3", "backgroundb3", 256, 256);
    NF_CreateTiledBg(0, 3, "backgroundt");
    NF_CreateTiledBg(1, 3, "backgroundb");
    NF_CreateTiledBg(1, 2, "backgroundb2");
    NF_CreateTiledBg(1, 1, "backgroundb3");   	 
    NF_ClearTextLayer(1,0); 
    borrarmenu(); 
    NF_LoadSpriteGfx("sprite/hand", 0, 32, 32);
    NF_LoadSpritePal("sprite/hand", 0);
    NF_LoadSpriteGfx("sprite/token", 2, 32, 32);
    NF_LoadSpritePal("sprite/token", 2);
    NF_LoadSpriteGfx("sprite/css_mario", 3, 32, 32);
    NF_LoadSpritePal("sprite/css_mario", 3);
    NF_LoadSpriteGfx("sprite/css_tlink", 4, 32, 32);
    NF_LoadSpritePal("sprite/css_tlink", 4);
    NF_LoadSpriteGfx("sprite/css_samus", 5, 32, 32);
    NF_LoadSpritePal("sprite/css_samus", 5);
    NF_LoadSpriteGfx("sprite/css_fox",6, 32, 32);
    NF_LoadSpritePal("sprite/css_fox",6);
    NF_LoadSpriteGfx("sprite/css_kirby", 7, 32, 32);
    NF_LoadSpritePal("sprite/css_kirby", 7);
    NF_LoadSpriteGfx("sprite/css_pikachu",8, 32, 32);
    NF_LoadSpritePal("sprite/css_pikachu",8);
    NF_LoadSpriteGfx("sprite/css_falcon",9, 32, 32);
    NF_LoadSpritePal("sprite/css_falcon",9);
    NF_LoadSpriteGfx("sprite/css_luigi",10, 32, 32);
    NF_LoadSpritePal("sprite/css_luigi",10);
    NF_LoadSpriteGfx("sprite/css_ness",11, 32, 32);
    NF_LoadSpritePal("sprite/css_ness",11);
    NF_LoadSpriteGfx("sprite/css_pit",12, 32, 32);
    NF_LoadSpritePal("sprite/css_pit",12);
    NF_LoadSpriteGfx("sprite/css_falco",13, 32, 32);
    NF_LoadSpritePal("sprite/css_falco",13);
    NF_LoadSpriteGfx("sprite/css_mk",14, 32, 32);
    NF_LoadSpritePal("sprite/css_mk",14);
    NF_LoadSpriteGfx("sprite/css_mew2",15, 32, 32);
    NF_LoadSpritePal("sprite/css_mew2",15);
    NF_LoadSpriteGfx("sprite/css_gnw",16, 32, 32);
    NF_LoadSpritePal("sprite/css_gnw",16);
    NF_LoadSpriteGfx("sprite/css_wario",17, 32, 32);
    NF_LoadSpritePal("sprite/css_wario",17);
    NF_LoadSpriteGfx("sprite/css_lucas",18, 32, 32);
    NF_LoadSpritePal("sprite/css_lucas",18);
    NF_LoadSpriteGfx("sprite/css_lilmac",19, 32, 32);
    NF_LoadSpritePal("sprite/css_lilmac",19);
    NF_LoadSpriteGfx("sprite/css_snake",20, 32, 32);
    NF_LoadSpritePal("sprite/css_snake",20);
    NF_LoadSpriteGfx("sprite/css_marth",21, 32, 32);
    NF_LoadSpritePal("sprite/css_marth",21);
    NF_LoadSpriteGfx("sprite/css_puff",22, 32, 32);
    NF_LoadSpritePal("sprite/css_puff",22);
    NF_LoadSpriteGfx("sprite/css_diddy",23, 32, 32);
    NF_LoadSpritePal("sprite/css_diddy",23);
    NF_LoadSpriteGfx("sprite/css_villager",24, 32, 32);
    NF_LoadSpritePal("sprite/css_villager",24);
    NF_LoadSpriteGfx("sprite/css_megaman",25, 32, 32);
    NF_LoadSpritePal("sprite/css_megaman",25);
    NF_LoadSpriteGfx("sprite/css_sonic",26, 32, 32);
    NF_LoadSpritePal("sprite/css_sonic",26);
    NF_LoadSpriteGfx("sprite/css_pac",27, 32, 32);
    NF_LoadSpritePal("sprite/css_pac",27);
    NF_LoadSpriteGfx("sprite/css_sora",28, 32, 32);
    NF_LoadSpritePal("sprite/css_sora",28);
    NF_LoadSpriteGfx("sprite/css_neku",29, 32, 32);
    NF_LoadSpritePal("sprite/css_neku",29);
    NF_LoadSpriteGfx("sprite/css_wright",30, 32, 32);
    NF_LoadSpritePal("sprite/css_wright",30);
    NF_LoadSpriteGfx("sprite/css_random",31,32,32);
    NF_LoadSpritePal("sprite/css_random",31);
    
    
    
    
    
    
     
    
    NF_Vram3dSpriteGfx(0, 0,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(0, 0);
    NF_Vram3dSpriteGfx(2, 2,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(2, 2);
    NF_Vram3dSpriteGfx(3, 3,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(3, 3);
    NF_Vram3dSpriteGfx(4, 4,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(4, 4);
    NF_Vram3dSpriteGfx(5, 5,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(5, 5);
    NF_Vram3dSpriteGfx(6, 6,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(6, 6);
    NF_Vram3dSpriteGfx(7, 7,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(7, 7);
    NF_Vram3dSpriteGfx(8, 8,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(8, 8);
    NF_Vram3dSpriteGfx(9, 9,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(9, 9 );
    NF_Vram3dSpriteGfx(10, 10,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(10,10 );
    NF_Vram3dSpriteGfx(11, 11,true); // Poniendo los sprites en la VRAM
    NF_Vram3dSpritePal(11,11 );
    NF_Vram3dSpriteGfx(12, 12,true); 
    NF_Vram3dSpritePal(12,12 );
    NF_Vram3dSpriteGfx(13, 13,true);
    NF_Vram3dSpritePal(13,13 );
    NF_Vram3dSpriteGfx(14,14,true); 
    NF_Vram3dSpritePal(14,14 );
    NF_Vram3dSpriteGfx(15,15,true);
    NF_Vram3dSpritePal(15,15 );
    NF_Vram3dSpriteGfx(16,16,true); 
    NF_Vram3dSpritePal(16,16 );
    NF_Vram3dSpriteGfx(17,17,true); 
    NF_Vram3dSpritePal(17,17 );
    NF_Vram3dSpriteGfx(18,18,true); 
    NF_Vram3dSpritePal(18,18 );
    NF_Vram3dSpriteGfx(19,19,true); 
    NF_Vram3dSpritePal(19,19 );
    NF_Vram3dSpriteGfx(20,20,true); 
    NF_Vram3dSpritePal(20,20 );
    NF_Vram3dSpriteGfx(21,21,true); 
    NF_Vram3dSpritePal(21,21);
    NF_Vram3dSpriteGfx(22,22,true); 
    NF_Vram3dSpritePal(22,22);
    NF_Vram3dSpriteGfx(23,23,true); 
    NF_Vram3dSpritePal(23,23 );
    NF_Vram3dSpriteGfx(24,24,true); 
    NF_Vram3dSpritePal(24,24 );
    NF_Vram3dSpriteGfx(25,25,true); 
    NF_Vram3dSpritePal(25,25 );
    NF_Vram3dSpriteGfx(26,26,true); 
    NF_Vram3dSpritePal(26,26 );
    NF_Vram3dSpriteGfx(27,27,true); 
    NF_Vram3dSpritePal(27,27 );
    NF_Vram3dSpriteGfx(28,28,true); 
    NF_Vram3dSpritePal(28,28 );
    NF_Vram3dSpriteGfx(29,29,true); 
    NF_Vram3dSpritePal(29,29 );
    NF_Vram3dSpriteGfx(30,30,true); 
    NF_Vram3dSpritePal(30,30 );
    NF_Vram3dSpriteGfx(31,31,true); 
    NF_Vram3dSpritePal(31,31 );
   
   
   
   
   
    
    
     
    
    NF_Create3dSprite(0, 0, 0,144,17);
    NF_Create3dSprite(2, 2, 2,100,150);
    NF_Create3dSprite(3, 3, 3,20,17);
    NF_Create3dSprite(4, 4, 4,51,17);
    NF_Create3dSprite(5, 5, 5,82,17);
    NF_Create3dSprite(6, 6, 6,113,17);
    NF_Create3dSprite(7,7,7,144,17);
    NF_Create3dSprite(8,8,8,175,17);
    NF_Create3dSprite(9,9,9,206,17);
    NF_Create3dSprite(10,10,10,20,48);
    NF_Create3dSprite(11,11,11,51,48);
    NF_Create3dSprite(12,12,12,82,48);
    NF_Create3dSprite(13,13,13,113,48);
    NF_Create3dSprite(14,14,14,144,48);
    NF_Create3dSprite(15,15,15,175,48);
    NF_Create3dSprite(16,16,16,206,48);
    NF_Create3dSprite(17,17,17,35,79);
    NF_Create3dSprite(18,18,18,66,79);
    NF_Create3dSprite(19,19,19,97,79);
    NF_Create3dSprite(20,20,20,128,79);
	NF_Create3dSprite(21,21,21,159,79);	
	NF_Create3dSprite(22,22,22,190,79);
	NF_Create3dSprite(23,23,23,50,110);
	NF_Create3dSprite(24,24,24,81,110);
	NF_Create3dSprite(25,25,25,112,110);  //megaman
	NF_Create3dSprite(26,26,26,143,110);
	NF_Create3dSprite(27,27,27,174,110);
	NF_Create3dSprite(28,28,28,65,141);
	NF_Create3dSprite(29,29,29,96,141);
	NF_Create3dSprite(30,30,30,127,141);  
	NF_Create3dSprite(31,31,31,158,141);   
    glFlush(0);
   mmEffectEx(&ffa); 
    
   
         	
         	 break;
         	 
         	 
         	 
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
     
        powerOn(POWER_ALL);
    
    
    
   // char segundos[200];
    s16 bgX = 0;
    s16 fadeX = 0;
    s16 fadeY = 0;
    s16 titlestate =0;
    s16 seconds=0;
    //indican donde comienza la posicion de las barras del menu principal
    s16 mbgsY=-4;
    s16 mbgsY2=4;
    s16 mh1=0;
    s16 mh2=0;
    s16 handx = 0; 
    s16 handy = 0; 
    s16 hstate = 0;
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
    // snprintf(segundos, sizeof(segundos), "Segundos: %d %d %d %d ", seconds,btn_anid,currentRoom,mbgsY2);
     
          //  NF_WriteText(1, 0, 1, 1, segundos);
    
       btn_anim++;
        if (btn_anim >0.5 && btn_anid==0 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 7)
                btn_frame = 7;
            NF_Set3dSpriteFrame(1,btn_frame);
            NF_Set3dSpriteFrame(2,btn_frame);
        } 
         if (btn_anim >0.5 && btn_anid==1 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 8)
                btn_frame = 8;
            NF_Set3dSpriteFrame(3,btn_frame);
            NF_Set3dSpriteFrame(4,btn_frame);
        } 
         if (btn_anim >0.5 && btn_anid==2 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 7)
                btn_frame = 7;
            NF_Set3dSpriteFrame(5,btn_frame);
            
        } 
         if (btn_anim >0.5 && btn_anid==4 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 13)
                btn_frame = 13;
            NF_Set3dSpriteFrame(7,btn_frame);
            
        } 
           if (btn_anim >1 && btn_anid==3 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 11)
                btn_frame = 11;
            NF_Set3dSpriteFrame(6,btn_frame); 
            
        } 
            if (btn_anim >0.9 && btn_anid==5 && currentRoom==2 )
        {   
            btn_anim = 0;
            btn_frame ++;
            
            if (btn_frame > 11)
                btn_frame = 11;
            NF_Set3dSpriteFrame(8,btn_frame); 
            
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
		   mh1+=1;
           mh2+=1;
           NF_ScrollBg(1,3,mh1,mh2);  
           NF_ScrollBg(0,1,0,mbgsY);  
           NF_ScrollBg(0,2,0,mbgsY2);   
          
         }     
         	 if (currentRoom==1 && fadeX>=13 && titlestate==1 ) {
           NF_ClearTextLayer(1,0); 
               
               
           
         }     
            
	
	
    	   scanKeys(); 
       
        
        
        
        
        if (keysDown() & KEY_UP && currentRoom==2) {
             mmEffectEx(&cursor); 
             NF_ClearTextLayer(1,0);
        }    
		
		 if (keysDown() & KEY_DOWN && btn_anid==0 && currentRoom==2 ) {
             mmEffectEx(&cursor); 
            NF_ClearTextLayer(1,0);
             btn_frame=0;
             btn_anid=2;  
        }     
         if (keysDown() & KEY_DOWN && btn_anid==1 && currentRoom==2)  {
             mmEffectEx(&cursor); 
              NF_ClearTextLayer(1,0);
             btn_frame=0;
             btn_anid=4;  
        }     
         if (keysDown() & KEY_UP && btn_anid==4 && currentRoom==2 ) {
             mmEffectEx(&cursor); 
            NF_ClearTextLayer(1,0);
             btn_frame=0;
             btn_anid=1;  
        }     
         if (keysDown() & KEY_UP && btn_anid==3 && currentRoom==2) {
             mmEffectEx(&cursor); 
            NF_ClearTextLayer(1,0);
             btn_frame=0;
             btn_anid=1;  
             
			 }
         if (keysDown() & KEY_UP && btn_anid==2 && currentRoom==2) {
         	 NF_ClearTextLayer(1,0);
             mmEffectEx(&cursor); 
             btn_frame=0;
             btn_anid=0;
        }
         if (keysDown() & KEY_UP && btn_anid==5 && currentRoom==2) {
         	 NF_ClearTextLayer(1,0);
             mmEffectEx(&cursor); 
             btn_frame=0;
             btn_anid=1;
        }
          if (keysDown() & KEY_RIGHT && btn_anid>=5  && currentRoom==2) {
         	 NF_ClearTextLayer(1,0);
             mmEffectEx(&cursor); 
             btn_frame=0;
             btn_anid=1;
        }
        
		 if (keysDown() & KEY_RIGHT && currentRoom==2) {
		 	 NF_ClearTextLayer(1,0);
             mmEffectEx(&cursor); 
             btn_frame=0;
             btn_anid++;
        }  
         if (keysDown() & KEY_LEFT && currentRoom==2 ) {
         	 NF_ClearTextLayer(1,0);
             mmEffectEx(&cursor);  
             btn_frame=0;
             btn_anid--;
        }  
		  
        
         
         	 if (keysDown() & KEY_START && currentRoom==1 && titlestate==0) {
         	fadeX= 0;
            fadeY= 0;	
         	seconds=0; 	
            titlestate=1;
            
            mmEffectEx(&start); 

        }     
        
        	 if (keysDown() & KEY_A && currentRoom==2) {
             changeRoom(currentRoom=3); 
            
            

        }   
          	 if (titlestate==1 && currentRoom==1) {
           
	
        }     
         
          	 if (seconds==30 && titlestate==1) {
           changeRoom(currentRoom=2); 
           seconds=0;
          
        }     
         	 if (seconds==0 && currentRoom==1 && titlestate==1) {
         fadeToWhite();
          
        }     
        	 if (btn_anid!=0 && currentRoom==2) {
            NF_Set3dSpriteFrame(1,0);
            NF_Set3dSpriteFrame(2,0);
            
         }    
         	 if (btn_anid==0 && currentRoom==2) {
            NF_WriteText(1,0, 4, 22, "Play a variety of modes!"); 
         }    
         	 if (btn_anid==1 && currentRoom==2) {
         	
            NF_WriteText(1,0, 6, 22, "Play this mode solo!"); 
         }    
         	 if (btn_anid==2 && currentRoom==2) {
         	
            NF_WriteText(1,0, 15, 22, "???"); 
         }    
         	 if (btn_anid==3 && currentRoom==2) {
         	
            NF_WriteText(1,0,2, 22, "View trophies and snapshots!"); 
         }    
         	 if (btn_anid==4 && currentRoom==2) {
         	
            NF_WriteText(1,0, 6, 22, "Choose your settings.");        
         }    
          if (btn_anid==5 && currentRoom==2) {
         	
            NF_WriteText(1,0, 3, 22, "Manage or delete your data.");        
         }    
         
		 	 if (btn_anid!=1 && currentRoom==2) {
            NF_Set3dSpriteFrame(3,0);
            NF_Set3dSpriteFrame(4,0);
         }     
         	 if (btn_anid!=2 && currentRoom==2) { 
            NF_Set3dSpriteFrame(5,0);
           
         } 
         	 if (btn_anid!=3 && currentRoom==2) {
            NF_Set3dSpriteFrame(6,0);
           
         } 
         	 if (btn_anid!=5 && currentRoom==2) {
            NF_Set3dSpriteFrame(8,0);
           
         } 
         	 if (btn_anid!=4 && currentRoom==2) {
            NF_Set3dSpriteFrame(7,0);
           
         } 
		 	 if (btn_anid<0 && currentRoom==2) {
            btn_anid=2;
           
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
