#ifndef __MD2_H
#define __MD2_H
#ifdef __cplusplus
extern "C"{
#endif

extern float precomputedNormals[162][3];

struct MD2Header {
    unsigned int identity;
    unsigned int version;
    unsigned int skinWidth;
    unsigned int skinHeight;
    unsigned int frameSize;

    unsigned int textureCount;
    unsigned int vertexCount;
    unsigned int unwrapCount;
    unsigned int faceCount;
    unsigned int commandCount;
    unsigned int frameCount;

    unsigned int textureOffset;
    unsigned int unwrapOffset;
    unsigned int faceOffset;
    unsigned int frameOffset;
    unsigned int commandOffset;
    unsigned int endOffset;
};

struct MD2Texture {
    char name[64];
};

struct MD2Unwrap {
    short s;
    short t;
};

struct MD2Face {
    unsigned short vertexIndex[3];
    unsigned short unwrapIndex[3];
};

struct MD2Vertex {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char normalIndex;
};

struct MD2Frame {
    float scaleX;
    float scaleY;
    float scaleZ;
    float positionX;
    float positionY;
    float positionZ;
    char name[16];
};

struct MD2 {
    struct MD2Header *header;
    struct MD2Texture *textures;
    struct MD2Unwrap *unwraps;
    struct MD2Face *faces;
    struct MD2Frame *frames;
};

struct MD2Frame *md2GetFrame(struct MD2 *md2, unsigned int index);
struct MD2Vertex *md2GetVerticies(struct MD2Frame *frame, unsigned int index);

#ifdef __cplusplus
}
#endif
#endif
