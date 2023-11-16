#include "md2_parser.h"

static char boundryCheck(
    unsigned int totalSize,
    unsigned int startOffset,
    unsigned int objSize,
    unsigned int objCount) {
    return startOffset + objSize * objCount < totalSize;
}

static int parseMD2Header(struct MD2* md2, char* buffer, unsigned int size) {
    if (sizeof(struct MD2Header) > size) return 0;
    md2->header = (struct MD2Header*) buffer;
    return 1;
}

static int parseMD2Textures(struct MD2* md2, char* buffer, unsigned int size) {
    unsigned int textureOffset = md2->header->textureOffset;
    unsigned int textureCount = md2->header->textureCount;
    if(boundryCheck(size, textureOffset, sizeof(struct MD2Texture), textureCount))
        return 0;
    md2->textures = (struct MD2Texture*) (buffer + textureOffset);
    return 1;
}

static int parseMD2Unwraps(struct MD2* md2, char* buffer, unsigned int size) {
    unsigned int unwrapOffset = md2->header->unwrapOffset;
    unsigned int unwrapCount = md2->header->unwrapCount;
    if(boundryCheck(size, unwrapOffset, sizeof(struct MD2Unwrap), unwrapCount))
        return 0;
    md2->unwraps = (struct MD2Unwrap*) (buffer + unwrapOffset);
    return 1;
}

static int parseMD2Faces(struct MD2* md2, char* buffer, unsigned int size) {
    unsigned int faceOffset = md2->header->faceOffset;
    unsigned int faceCount = md2->header->faceCount;
    if(boundryCheck(size, faceOffset, sizeof(struct MD2Face), faceCount))
        return 0;
    md2->faces = (struct MD2Face*) (buffer + faceOffset);
    return 1;
}

static int parseMD2Frames(struct MD2* md2, char* buffer, unsigned int size) {
    unsigned int frameOffset = md2->header->frameOffset;
    unsigned int frameCount = md2->header->frameCount;
    unsigned int vertexCount = md2->header->vertexCount;
    unsigned int frameSize = sizeof(struct MD2Frame) + (vertexCount - 1) * sizeof(struct MD2Vertex);
    if(boundryCheck(size, frameOffset, frameSize, frameCount))
        return 0;
    md2->frames = (struct MD2Frame*) (buffer + frameOffset);
    return 1;
}

unsigned int parseMD2(struct MD2* md2, char* buffer, unsigned int size) {
    return parseMD2Header(md2, buffer, size) &&
           parseMD2Textures(md2, buffer, size) &&
           parseMD2Unwraps(md2, buffer, size) &&
           parseMD2Faces(md2, buffer, size) &&
           parseMD2Frames(md2, buffer, size);
}
