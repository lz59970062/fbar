/*
 * *************************************************************************
 * * FILE: text.c
 * * DESCRIPTION: get data from text
 * *************************************************************************
 */

module textGet
{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ldata.h" /* Main UPI header. */

#define PI 3.14159265358979323846
#define SIZE 1000
#define NUM_WG_POINTS 5
#define LEN_TEXT_WID 5
#define LEN_TEXT_HEI 40
#define POS_TEXT_X_STA -1000
#define POS_TEXT_Y_CEN 200

#define base_width 0.46
#define gap 0.15
#define radius 8.5

    //circle   1
    void drawC_1(LCell Cell, LLayer Layer, double offsetX, double offsetY)
    {
        int i = 0;
        int cnt = 5;
        float x[5], y[5];

        LPoint *points;

        //装点
        //wai
        x[0] = -30;
        x[1] = -95;
        x[2] = -60;
        x[3] = 30;
        x[4] = 60;

        y[0] = 75;
        y[1]=0;
        y[2]=-85;
        y[3]=-85;
        y[4]=0;

        points = (LPoint *)malloc((cnt) * sizeof(LPoint)); //get arm
        for (i = 0; i < cnt; i++)
        {
            points[i] = LPoint_Set(x[i] * SIZE + offsetX, y[i] * SIZE + offsetY);
        }
        LPolygon_New(Cell, Layer, points, cnt);
        free(points);
        return;
    }

    void drawRowland()
    {
        /*
		 * 绘图函数的入参必须指定cell、文件和图层，需先获取
		 * 获取当前cell和文件
		 */
        LCell Cell_Now = LCell_GetVisible();
        LFile File_Now = LCell_GetFile(Cell_Now);

        /* 获取当前图层 */
        LLayer Layer_Poly = LLayer_Find(File_Now, "Poly");
        if (!Layer_Poly)
        {
            LDialog_AlertBox("There is no Poly layer.\nMake sure Poly is in the layer map!");
            return;
        }

        LLayer Layer_Active = LLayer_Find(File_Now, "Active");
        if (!Layer_Active)
        {
            LDialog_AlertBox("There is no Active layer.\nMake sure Poly is in the layer map!");
            return;
        }

        LLayer Layer_Metal1 = LLayer_Find(File_Now, "Metal1");
        if (!Layer_Metal1)
        {
            LDialog_AlertBox("There is no N Select layer.\nMake sure Metal1 is in the layer map!");
            return;
        }

        double offsetX = 0;
        double offsetY = 0;

        //circle
        drawC_1(Cell_Now, Layer_Active, offsetX, offsetY);

        return;
    }

    void drawRowland_main(void)
    {
        LMacro_BindToHotKey(KEY_F1, "drawRowland", "drawRowland");
    }
} /* end of module textGet */

drawRowland_main();