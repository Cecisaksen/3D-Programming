#include "HeightMap.h"
#include "Vertex.h"
#include "stb_image.h"
#include <QDebug>

HeightMap::HeightMap() : VisualObject()
{
  makeTerrain("../../Assets/Heightmap.jpg");
    mMatrix.translate(0, 0 ,0);
  mName = "HeightMap";
    drawType=0;
}

//float HeightMap::GetHeight(float x, float z)
//{
    //QVector3D  cartesianToBarycentric2(QVector2D p, QVector2D a, QVector2D b, QVector2D c)
    //{
        //QVector2D v0 = { b.x - a.x, b.y - a.y };
        //QVector2D v1 = { c.x - a.x, c.y - a.y };
        //QVector2D v2 = { p.x - a.x, p.y - a.y };
        //float d00 = QVector2D::dotProduct(v0, v0);
        //float d01 = QVector2D::dotProduct(v0, v1);
        //float d11 = QVector2D::dotProduct(v1, v1);
        //float d20 = QVector2D::dotProduct(v2, v0);
        //float d21 = QVector2D::dotProduct(v2, v1);
       // float denom = d00 * d11 - d01 * d01;
      //  float alpha = (d11 * d20 - d01 * d21) / denom;
      //  float beta = (d00 * d21 - d01 * d20) / denom;
      //  float gamma = 1.0f - alpha - beta;
     //   return QVector3D( alpha, beta, gamma );
    //}

//}

void HeightMap::makeTerrain(std::string heightMapImage)
{
    bool validPath = Image.load(heightMapImage.c_str());
    if(!validPath) {
        throw;
    }

    Image = QImage(heightMapImage.c_str());

    int height;
    int width;

    width = Image.width();
    height= Image.height();

    for(
        int y = 0;
        y < height;
        y++) {
        for (int x = 0;
        x < width;
             x++) {
            QRgb value = Image.pixel(x,y);
            float zHeight = float(qGray(value)) / 255 * 20;
            float vx=x*0.5;
            float vy=zHeight;
            float vz=y*0.5;

            float u = float(x)/float(width);
            float v = float(y)/float(height);

            mVertices.push_back({
                vx,vy,vz,0,0,0,u,v
                       });

            if(x == width-1 || y == height-1) continue;

            if(y+1 >255) {
                qDebug() << "foo";
                int foo = y+1;
                foo;
            }

            int indexOne = (x) + (y) * width;
            int indexTwo = (x) + (y+1)* width;
            int indexThree = (x + 1) + (y + 1)* width;
            int indexFour = (x + 1) + (y)* width;
            mIndices.push_back(indexOne);
            mIndices.push_back(indexTwo);
            mIndices.push_back(indexFour);
            mIndices.push_back(indexTwo);
            mIndices.push_back(indexThree);
            mIndices.push_back(indexFour);

        }


    }



}


