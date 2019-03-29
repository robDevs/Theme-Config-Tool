/*******************************************************************************************
*
*   layout_file_name - Create Theme Config Files For RPPHS
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 RBDev
*
**********************************************************************************************/

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void SaveButton(char* fileName);		// Button: SaveButton logic
static bool file_exists( char* filename);
static void drawMessage(char* message);

    int MainTextRValValue = 0;
    int MainTextGValValue = 0;
    int MainTextBValValue = 0;
    
    int HelpTextRValValue = 0;
    int HelpTextGValValue = 0;
    int HelpTextBValValue = 0;
    
    int BorderRValValue = 0;
    int BorderGValValue = 0;
    int BorderBValValue = 0;
    
    int MenuBGRValValue = 0;
    int MenuBGGValValue = 0;
    int MenuBGBValValue = 0;
    
    int MenuBarRValValue = 0;
    int MenuBarGValValue = 0;
    int MenuBarBValValue = 0;
    
    int GaryRValValue = 0;
    int GaryGValValue = 0;
    int GaryBValValue = 0;
    
    int JeffRValValue = 0;
    int JeffGValValue = 0;
    int JeffBValValue = 0;
    
    int MiniJeffRValValue = 0;
    int MiniJeffGValValue = 0;
    int MiniJeffBValValue = 0;
    
    int KarenRValValue = 0;
    int KarenGValValue = 0;
    int KarenBValValue = 0;
    
    int SnakeRValValue = 0;
    int SnakeGValValue = 0;
    int SnakeBValValue = 0;
    
    int BulletRValValue = 0;
    int BulletGValValue = 0;
    int BulletBValValue = 0;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int messageTimer = 300;
    int screenWidth = 680;
    int screenHeight = 385;

    int red = 0;
    int green = 0; 
    int blue = 0;

    bool redEdit = false;
    bool greenEdit = false;
    bool blueEdit = false;

    bool textEdit = false;

    bool fileExists;

    bool helpBoxWindowActive = false;

    InitWindow(screenWidth, screenHeight, "Theme Config Tool");
    //GuiLoadStyle("configToolStyle.rgs"); Wait for updates to rGuiStyler for this. 

    // layout_file_name: controls initialization
    //----------------------------------------------------------------------------------

    Color ColorPickerValue;
    
    int FileTextBoxSize = 32;
    char FileTextBoxText[32] = "";

    #define MainTextBox 1
    #define HelpTextBox 5
    #define BorderBox   9
    #define MenuBGBox   13
    #define MenuBarBox  17
    #define GaryBox     21
    #define JeffBox     25
    #define MiniJeffBox 29
    #define KarenBox    33
    #define SnakeBox    37
    #define BulletBox   41
    #define FileNameBox 45

    // Define controls rectangles
    Rectangle layoutRecs[49] = {
        (Rectangle){ 350, 25, 250, 250 },		// ColorPicker: ColorPicker
        (Rectangle){ 50, 25, 125, 45 },		// GroupBox: MainTextBox
        (Rectangle){ 60, 35, 25, 25 },		// ValueBox: MainTextRVal
        (Rectangle){ 85, 35, 25, 25 },		// ValueBox: MainTextGVal
        (Rectangle){ 110, 35, 25, 25 },		// ValueBox: MainTextBVal

        (Rectangle){ 50, 85, 125, 45 },		// GroupBox: HelpTextBox
        (Rectangle){ 60, 95, 25, 25 },		// ValueBox: HelpTextRVal
        (Rectangle){ 85, 95, 25, 25 },		// ValueBox: HelpTextGVal
        (Rectangle){ 110, 95, 25, 25 },		// ValueBox: HelpTextBVal

        (Rectangle){ 50, 145, 124, 45 },		// GroupBox: BorderBox
        (Rectangle){ 60, 155, 25, 25 },		// ValueBox: BorderRVal
        (Rectangle){ 85, 155, 25, 25 },		// ValueBox: BorderGVal
        (Rectangle){ 110, 155, 25, 25 },		// ValueBox: BorderBVal

        (Rectangle){ 50, 205, 125, 45 },		// GroupBox: MenuBGBox
        (Rectangle){ 60, 215, 25, 25 },		// ValueBox: MenuBGRVal
        (Rectangle){ 85, 215, 25, 25 },		// ValueBox: MenuBGGVal
        (Rectangle){ 110, 215, 25, 25 },		// ValueBox: MenuBGBVal

        (Rectangle){ 50, 265, 125, 45 },		// GroupBox: MenuBarBox
        (Rectangle){ 60, 275, 25, 25 },		// ValueBox: MenuBarRVal
        (Rectangle){ 85, 275, 25, 25 },		// ValueBox: MenuBarGVal
        (Rectangle){ 110, 275, 25, 25 },		// ValueBox: MenuBarBVal

        (Rectangle){ 50, 325, 125, 45 },		// GroupBox: GaryBox
        (Rectangle){ 60, 335, 25, 25 },		// ValueBox: GaryRVal
        (Rectangle){ 85, 335, 25, 25 },		// ValueBox: GaryGVal
        (Rectangle){ 110, 335, 25, 25 },		// ValueBox: GaryBVal

        (Rectangle){ 190, 25, 125, 45 },		// GroupBox: JeffBox
        (Rectangle){ 200, 35, 25, 25 },		// ValueBox: JeffRVal
        (Rectangle){ 225, 35, 25, 25 },		// ValueBox: JeffGVal
        (Rectangle){ 250, 35, 25, 25 },		// ValueBox: JeffBVal

        (Rectangle){ 190, 85, 125, 45 },		// GroupBox: MiniJeffBox
        (Rectangle){ 200, 95, 25, 25 },		// ValueBox: MiniJeffRVal
        (Rectangle){ 225, 95, 25, 25 },		// ValueBox: MiniJeffGVal
        (Rectangle){ 250, 95, 25, 25 },		// ValueBox: MiniJeffBVal

        (Rectangle){ 190, 145, 125, 45 },		// GroupBox: KarenBox
        (Rectangle){ 200, 155, 25, 25 },		// ValueBox: KarenRVal
        (Rectangle){ 225, 155, 25, 25 },		// ValueBox: KarenGVal
        (Rectangle){ 250, 155, 25, 25 },		// ValueBox: KarenBVal

        (Rectangle){ 190, 205, 125, 45 },		// GroupBox: SnakeBox
        (Rectangle){ 200, 215, 25, 25 },		// ValueBox: SnakeRVal
        (Rectangle){ 225, 215, 25, 25 },		// ValueBox: SnakeGVal
        (Rectangle){ 250, 215, 25, 25 },		// ValueBox: SnakeBVal

        (Rectangle){ 190, 265, 125, 45 },		// GroupBox: BulletBox
        (Rectangle){ 200, 275, 25, 25 },		// ValueBox: BulletRVal
        (Rectangle){ 225, 275, 25, 25 },		// ValueBox: BulletGVal
        (Rectangle){ 250, 275, 25, 25 },		// ValueBox: BulletBVal

        (Rectangle){ 190, 325, 275, 45 },		// GroupBox: FileNameBox

        (Rectangle){ 200, 335, 175, 25 },		// TextBox: FileTextBox

        (Rectangle){ 570, 325, 60, 45 },		// Button: HelpButton
        
        (Rectangle){ 495, 325, 65, 45 }		// Button: SaveButton
    };

    Rectangle redRect = {layoutRecs[0].x, layoutRecs[0].y + layoutRecs[0].height + 10, 25, 25};
    Rectangle greenRect = {layoutRecs[0].x + 25, layoutRecs[0].y + layoutRecs[0].height + 10, 25, 25};
    Rectangle blueRect = {layoutRecs[0].x + 50, layoutRecs[0].y + layoutRecs[0].height + 10, 25, 25};


    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        if(!redEdit) red = ColorPickerValue.r;
        if(!greenEdit) green = ColorPickerValue.g;
        if(!blueEdit) blue = ColorPickerValue.b;

        if(IsKeyReleased(KEY_ENTER))
        {
            redEdit = false;
            greenEdit = false;
            blueEdit = false;

            ColorPickerValue.r = red;
            ColorPickerValue.g = green;
            ColorPickerValue.b = blue;

            textEdit = false;

            fileExists = file_exists(FileTextBoxText);
        }

        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, redRect) && !greenEdit && !blueEdit && !textEdit)
            {
                if(redEdit) redEdit = false;
                else redEdit = true;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, greenRect) && !redEdit && !blueEdit && !textEdit)
            {
                if(greenEdit) greenEdit = false;
                else greenEdit = true;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, blueRect) && !redEdit && !greenEdit && !textEdit)
            {
                if(blueEdit) blueEdit = false;
                else blueEdit = true;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[46]) && !redEdit && !greenEdit && !blueEdit)
            {
                if(textEdit) textEdit = false;
                else textEdit = true;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[MainTextBox]))
            {
                MainTextRValValue = red;
                MainTextGValValue = green;
                MainTextBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[HelpTextBox]))
            {
                HelpTextRValValue = red;
                HelpTextGValValue = green;
                HelpTextBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[BorderBox]))
            {
                BorderRValValue = red;
                BorderGValValue = green;
                BorderBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[MenuBGBox]))
            {
                MenuBGRValValue = red;
                MenuBGGValValue = green;
                MenuBGBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[MenuBarBox]))
            {
                MenuBarRValValue = red;
                MenuBarGValValue = green;
                MenuBarBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[GaryBox]))
            {
                GaryRValValue = red;
                GaryGValValue = green;
                GaryBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[JeffBox]))
            {
                JeffRValValue = red;
                JeffGValValue = green;
                JeffBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[MiniJeffBox]))
            {
                MiniJeffRValValue = red;
                MiniJeffGValValue = green;
                MiniJeffBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[KarenBox]))
            {
                KarenRValValue = red;
                KarenGValValue = green;
                KarenBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[SnakeBox]))
            {
                SnakeRValValue = red;
                SnakeGValValue = green;
                SnakeBValValue = blue;
            }

            if(CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY(),}, layoutRecs[BulletBox]))
            {
                BulletRValValue = red;
                BulletGValValue = green;
                BulletBValValue = blue;
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);
            GuiValueBox(redRect, &red, 0, 255, redEdit);
            GuiValueBox(greenRect, &green, 0, 255, greenEdit);
            GuiValueBox(blueRect, &blue, 0, 255, blueEdit);
            DrawRectangle(layoutRecs[0].x + 100, layoutRecs[0].y + layoutRecs[0].height + 10, 25, 25, (Color){red, green, blue, 255});

			// raygui: controls drawing
			//----------------------------------------------------------------------------------
			ColorPickerValue = GuiColorPicker(layoutRecs[0], ColorPickerValue);
			GuiGroupBox(layoutRecs[1], "Main Text Color");
		    GuiValueBox(layoutRecs[2], &MainTextRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[3], &MainTextGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[4], &MainTextBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[5], "Help Text Color");
			GuiValueBox(layoutRecs[6], &HelpTextRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[7], &HelpTextGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[8], &HelpTextBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[9], "Border Color");
			GuiValueBox(layoutRecs[10], &BorderRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[11], &BorderGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[12], &BorderBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[13], "Menu BG Color");
			GuiValueBox(layoutRecs[14], &MenuBGRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[15], &MenuBGGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[16], &MenuBGBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[17], "Menu Bar Color");
			GuiValueBox(layoutRecs[18], &MenuBarRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[19], &MenuBarGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[20], &MenuBarBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[21], "Gary Color");
			GuiValueBox(layoutRecs[22], &GaryRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[23], &GaryGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[24], &GaryBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[25], "Jeff Color");
			GuiValueBox(layoutRecs[26], &JeffRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[27], &JeffGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[28], &JeffBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[29], "Mini Jeff Color");
			GuiValueBox(layoutRecs[30], &MiniJeffRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[31], &MiniJeffGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[32], &MiniJeffBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[33], "Karen Color");
			GuiValueBox(layoutRecs[34], &KarenRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[35], &KarenGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[36], &KarenBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[37], "Snake Color");
			GuiValueBox(layoutRecs[38], &SnakeRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[39], &SnakeGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[40], &SnakeBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[41], "Bullet Color");
			GuiValueBox(layoutRecs[42], &BulletRValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[43], &BulletGValValue, 0, 255, false); 
			GuiValueBox(layoutRecs[44], &BulletBValValue, 0, 255, false); 
			GuiGroupBox(layoutRecs[45], "File Name");
			GuiTextBox(layoutRecs[46], FileTextBoxText, FileTextBoxSize, textEdit);

            if(fileExists) DrawText("File Already Exists and will be overwritten", layoutRecs[46].x, screenHeight - 10, 10, RED);

			if (GuiButton(layoutRecs[47], "Help?"))
            {
                if(helpBoxWindowActive) helpBoxWindowActive = false;
                else helpBoxWindowActive = true;
            } 


			if (GuiButton(layoutRecs[48], "Save") && !textEdit && strlen(FileTextBoxText) > 0)
            {
                for(int i = 0; i < strlen(FileTextBoxText); i++)
                {
                    if(FileTextBoxText[i] == ' ') FileTextBoxText[i] = '_';
                }
                SaveButton(FileTextBoxText); 
                messageTimer = 0;
            }

            if(messageTimer < 300)
            {
                messageTimer++;
                drawMessage("File saved");
            }

			//----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------

        while(helpBoxWindowActive && !WindowShouldClose())
        {
            BeginDrawing();

            ClearBackground(WHITE);

            helpBoxWindowActive = !GuiWindowBox((Rectangle){0,0,screenWidth, screenHeight}, "Help");
            DrawText("First Select a color with the color picker.\n"
            "Colors can be fined tuned with the boxes below the color picker.\n"
            "Once you have the color you want, click the box contating the variable you wish to change.\n"
            "When finished enter a file name and press enter.\n"
            "Click Save.\n\n"
            "Empty spaces in the file name will be replaced with underscores.\n"
            "(including leading and traling white space)", 10, 30, 10, BLACK);

            EndDrawing();
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

// Button: SaveButton logic
static void SaveButton(char* fileName)
{
    // TODO: Implement control logic
    FILE * fp;
    /* open the file for writing*/
    fp = fopen (fileName,"w");
 
    fprintf(fp, "mainTextColor\n{\n");
    fprintf(fp,"\tRed:%d\n",MainTextRValValue);
    fprintf(fp,"\tGreen:%d\n", MainTextGValValue);
    fprintf(fp,"\tBlue:%d\n", MainTextBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "helpTextColor\n{\n");
    fprintf(fp,"\tRed:%d\n",HelpTextRValValue);
    fprintf(fp,"\tGreen:%d\n", HelpTextGValValue);
    fprintf(fp,"\tBlue:%d\n", HelpTextBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "menuBorderColor\n{\n");
    fprintf(fp,"\tRed:%d\n",BorderGValValue);
    fprintf(fp,"\tGreen:%d\n", BorderRValValue);
    fprintf(fp,"\tBlue:%d\n", BorderBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "menuBGColor\n{\n");
    fprintf(fp,"\tRed:%d\n",MenuBGRValValue);
    fprintf(fp,"\tGreen:%d\n", MenuBGGValValue);
    fprintf(fp,"\tBlue:%d\n", MenuBGBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "menuBarColor\n{\n");
    fprintf(fp,"\tRed:%d\n",MenuBarRValValue);
    fprintf(fp,"\tGreen:%d\n", MenuBarGValValue);
    fprintf(fp,"\tBlue:%d\n", MenuBarBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "garyColor\n{\n");
    fprintf(fp,"\tRed:%d\n",GaryRValValue);
    fprintf(fp,"\tGreen:%d\n", GaryGValValue);
    fprintf(fp,"\tBlue:%d\n", GaryBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "jeffColor\n{\n");
    fprintf(fp,"\tRed:%d\n",JeffRValValue);
    fprintf(fp,"\tGreen:%d\n", JeffGValValue);
    fprintf(fp,"\tBlue:%d\n", JeffBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "miniColor\n{\n");
    fprintf(fp,"\tRed:%d\n",MiniJeffRValValue);
    fprintf(fp,"\tGreen:%d\n", MiniJeffGValValue);
    fprintf(fp,"\tBlue:%d\n", MiniJeffBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "karenColor\n{\n");
    fprintf(fp,"\tRed:%d\n",KarenRValValue);
    fprintf(fp,"\tGreen:%d\n", KarenGValValue);
    fprintf(fp,"\tBlue:%d\n", KarenBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "snakeColor\n{\n");
    fprintf(fp,"\tRed:%d\n",SnakeRValValue);
    fprintf(fp,"\tGreen:%d\n", SnakeGValValue);
    fprintf(fp,"\tBlue:%d\n", SnakeBValValue);
    fprintf(fp,"}\n");

    fprintf(fp, "bulletPColor\n{\n");
    fprintf(fp,"\tRed:%d\n",SnakeRValValue);
    fprintf(fp,"\tGreen:%d\n", SnakeGValValue);
    fprintf(fp,"\tBlue:%d\n", SnakeBValValue);
    fprintf(fp,"}\n");
 
    /* close the file*/  
    fclose (fp);
}

bool file_exists(char* filename)
{
    FILE * fp;
    if((fp = fopen(filename, "r")))
    {
        fclose(fp);
        return true;
    }
    return false;
}

void drawMessage(char* message)
{
    DrawRectangle(GetScreenWidth() / 2 - MeasureText(FormatText("%s", message), 20) / 2 - 10, 40,  MeasureText(FormatText("%s", message),20) + 20, 40, GRAY);
    DrawText(FormatText("%s", message), GetScreenWidth() / 2 - MeasureText(FormatText("%s", message),20)/2, 50, 20, BLACK);
}

