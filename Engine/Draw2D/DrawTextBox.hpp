










/*
#include <stdio.h>
#include "raylib/src/raylib.h"
#include <math.h>
#include <string.h>

Vector2  flaotToVec2(float angle) {
  return (Vector2){sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}


const char* const txts[] = {
  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce condimentum, erat porta consequat placerat, metus mauris suscipit eros, quis vulputate tellus ex et nunc. Sed in faucibus tortor. Sed at sem sit amet arcu suscipit vehicula. Mau",
  "ris commodo a nulla vel tempus. Vestibulum quis nisl interdum, luctus lacus ut, pharetra est. Morbi pretium sagittis augue eget porttitor. Aliquam at est eu libero cursus volutpat. Morbi vel elit massa. Nulla sit amet augue dolor. Vivamus lectus sem, euismod ut vestibulum sed, ullamcorper nec ante. Mauris rhoncus commodo lobortis. Vivamus mollis libero purus, vitae bibendum velit posuere ut. Suspendisse potenti.",
  "Vestibulum ac vehicula ligula, sit amet viverra enim. Sed et lobortis felis. Cras eu ultrices urna, suscipit mollis purus. Phasellus finibus auctor vehicula. Maecenas congue mauris diam, quis porta metus condimentum non. Morbi interdum metu",
  "s in nisi mattis efficitur. Aliquam posuere lorem id felis dictum, at gravida ex condimentum. Suspendisse accumsan diam quis varius varius.",
  "Nunc vitae leo non lectus porta lobortis eu non eros. Praesent fringilla tortor quis semper bibendum. Phasellus maximus eget diam vel ultricies. Nam vestibulum mi non tortor viverra placerat. Interdum et malesuada fames ac ante ipsum primis",
  " in faucibus. Sed lobortis libero non ipsum suscipit, id vulputate massa varius. Phasellus vitae elementum tortor.",
  "Phasellus non tortor pretium, malesuada risus id, hendrerit enim. Praesent efficitur venenatis aliquam. Vestibulum blandit justo diam. In vulputate vehicula leo at dictum. Maecenas id nunc ante. Mauris ac ante nec metus luctus iaculis sed l",
  "aoreet lacus. Fusce sit amet eros lectus. Donec tincidunt in sapien eu efficitur. Sed porttitor lacinia sodales. Fusce non justo quam. Maecenas ullamcorper orci semper magna ultrices, in luctus velit efficitur. Suspendisse potenti. Vivamus ultricies orci eget nisl suscipit, ut cursus massa egestas. Maecenas luctus vehicula odio, id placerat magna. Vivamus nec ipsum sit amet massa ornare sollicitudin sed sed dolor. Nulla interdum nisl orci, quis luctus magna suscipit vel.",
  "In aliquet, est vel scelerisque commodo, eros nisl elementum tellus, in varius risus leo in risus. Aenean posuere, quam quis accumsan ultrices, quam mi lacinia dolor, lobortis laoreet quam justo eu purus. Maecenas non consequat mi, pharetra",
  " aliquam mi. Sed vulputate lectus metus, ac fermentum lorem aliquam in. Sed semper ac purus ac semper. Curabitur congue sagittis pellentesque. Mauris non turpis non lorem luctus condimentum sed a ipsum. In justo justo, venenatis eleifend turpis a, fermentum tempus nibh. ",
  NULL
};




//  cc testfile.c raylib/src/libraylib.a -lGL -lm -lrt -lX11

  
size_t getSizeArray(const char* const* txts) {
  if (!txts)
    return 0;
  size_t s = 0;
  while (txts[s])
    s++;
  return s;
}

void DrawTextInBox(Rectangle box, const char* const* txts, size_t offset) {
  const size_t lenOfTxts = getSizeArray(txts);
  if (offset >= lenOfTxts)
    return ;
  const char* const* buffOffset = txts + offset;
  for (size_t list = 0; buffOffset[list]; list++) {
    const int slen = strlen(buffOffset[list]);
    char buff[slen + 1];
    memcpy(buff, buffOffset[list], slen);
    buff[slen] = 0;
    const int sizeText = MeasureText(buff, 10);
    int null = slen;
    while (MeasureText(buff, 10) > box.width - 40 - 12 && null > 0) {
      null--;
      buff[null] = 0;
    }
    if (box.height - 30 > (18 * list) + 28)
      DrawText(buff, 40, (18 * list) + 36, 10, GREEN);
  }
}

int main(void) {
  InitWindow(1000, 1000, "test");
  printf("test\n");
  SetTargetFPS(144);
  Texture2D texture = LoadTexture("cube.png");
  size_t offset = 0;
  const size_t txSize = getSizeArray(txts);
  while (!WindowShouldClose()) {
    Vector2 m = GetMousePosition();
    BeginDrawing();
    ClearBackground(BLACK);
    NPatchInfo nPatchInfo;
    int p = 10;
    nPatchInfo.bottom = p;
    nPatchInfo.source = (Rectangle){0,0, texture.width, texture.height};
    nPatchInfo.layout = 0;
    nPatchInfo.left = p;
    nPatchInfo.right = p;
    nPatchInfo.top = p;
    Rectangle dest = {30,30, m.x - 30 , m.y - 30};
    Vector2 origin = {0,0};
    DrawTextureNPatch(texture, nPatchInfo, dest, origin, 0, WHITE);
    Rectangle box = {30, 30, m.x, m.y};
    DrawTextInBox(box, txts, offset);
    EndDrawing();
    if (IsKeyPressed(KEY_UP) && offset < txSize)
      offset++;
    if (IsKeyPressed(KEY_DOWN) && offset)
      offset--;
  }
  UnloadTexture(texture);
  CloseWindow();
}
*/