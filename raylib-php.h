#define FFI_LIB "libraylib.so"

/**********************************************************************************************
*   LICENSE: zlib/libpng
*
*   raylib is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2013-2018 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

// This file is copied from raylib.h with minor changes:
// 1. All constants are moved to Raylib.php
// 2. All reference to Camera are replaced with Camera3D
// 3. MAX_SHADER_LOCATIONS and MAX_MATERIAL_MAPS are replaced with coresponding constants

//----------------------------------------------------------------------------------
// Structures Definition
//----------------------------------------------------------------------------------
// Vector2 type
typedef struct Vector2 {
    float x;
    float y;
} Vector2;

// Vector3 type
typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

// Vector4 type
typedef struct Vector4 {
    float x;
    float y;
    float z;
    float w;
} Vector4;

// Quaternion type, same as Vector4
typedef Vector4 Quaternion;

// Matrix type (OpenGL style 4x4 - right handed, column major)
typedef struct Matrix {
    float m0, m4, m8, m12;
    float m1, m5, m9, m13;
    float m2, m6, m10, m14;
    float m3, m7, m11, m15;
} Matrix;

// Color type, RGBA (32bit)
typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

// Rectangle type
typedef struct Rectangle {
    float x;
    float y;
    float width;
    float height;
} Rectangle;

// Image type, bpp always RGBA (32bit)
// NOTE: Data stored in CPU memory (RAM)
typedef struct Image {
    void *data;             // Image raw data
    int width;              // Image base width
    int height;             // Image base height
    int mipmaps;            // Mipmap levels, 1 by default
    int format;             // Data format (PixelFormat type)
} Image;

// Texture2D type
// NOTE: Data stored in GPU memory
typedef struct Texture2D {
    unsigned int id;        // OpenGL texture id
    int width;              // Texture base width
    int height;             // Texture base height
    int mipmaps;            // Mipmap levels, 1 by default
    int format;             // Data format (PixelFormat type)
} Texture2D;

// Texture type, same as Texture2D
typedef Texture2D Texture;

// RenderTexture2D type, for texture rendering
typedef struct RenderTexture2D {
    unsigned int id;        // OpenGL Framebuffer Object (FBO) id
    Texture2D texture;      // Color buffer attachment texture
    Texture2D depth;        // Depth buffer attachment texture
} RenderTexture2D;

// RenderTexture type, same as RenderTexture2D
typedef RenderTexture2D RenderTexture;

// Font character info
typedef struct CharInfo {
    int value;              // Character value (Unicode)
    Rectangle rec;          // Character rectangle in sprite font
    int offsetX;            // Character offset X when drawing
    int offsetY;            // Character offset Y when drawing
    int advanceX;           // Character advance position X
    unsigned char *data;    // Character pixel data (grayscale)
} CharInfo;

// Font type, includes texture and charSet array data
typedef struct Font {
    Texture2D texture;      // Font texture
    int baseSize;           // Base size (default chars height)
    int charsCount;         // Number of characters
    CharInfo *chars;        // Characters info data
} Font;

// #define SpriteFont Font     // SpriteFont type fallback, defaults to Font

// Camera type, defines a camera position/orientation in 3d space
typedef struct Camera3D {
    Vector3 position;       // Camera position
    Vector3 target;         // Camera target it looks-at
    Vector3 up;             // Camera up vector (rotation over its axis)
    float fovy;             // Camera field-of-view apperture in Y (degrees) in perspective, used as near plane width in orthographic
    int type;               // Camera type, defines projection type: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
} Camera3D;

// #define Camera Camera3D     // Camera type fallback, defaults to Camera3D

// Camera2D type, defines a 2d camera
typedef struct Camera2D {
    Vector2 offset;         // Camera offset (displacement from target)
    Vector2 target;         // Camera target (rotation and zoom origin)
    float rotation;         // Camera rotation in degrees
    float zoom;             // Camera zoom (scaling), should be 1.0f by default
} Camera2D;

// Bounding box type
typedef struct BoundingBox {
    Vector3 min;            // Minimum vertex box-corner
    Vector3 max;            // Maximum vertex box-corner
} BoundingBox;

// Vertex data definning a mesh
// NOTE: Data stored in CPU memory (and GPU)
typedef struct Mesh {
    int vertexCount;        // Number of vertices stored in arrays
    int triangleCount;      // Number of triangles stored (indexed or not)

    float *vertices;        // Vertex position (XYZ - 3 components per vertex) (shader-location = 0)
    float *texcoords;       // Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
    float *texcoords2;      // Vertex second texture coordinates (useful for lightmaps) (shader-location = 5)
    float *normals;         // Vertex normals (XYZ - 3 components per vertex) (shader-location = 2)
    float *tangents;        // Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4)
    unsigned char *colors;  // Vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
    unsigned short *indices;// Vertex indices (in case vertex data comes indexed)

    unsigned int vaoId;     // OpenGL Vertex Array Object id
    unsigned int vboId[7];  // OpenGL Vertex Buffer Objects id (7 types of vertex data)
} Mesh;

// Shader type (generic)
typedef struct Shader {
    unsigned int id;                // Shader program id
    int locs[32]; // Shader locations array
} Shader;

// Material texture map
typedef struct MaterialMap {
    Texture2D texture;      // Material map texture
    Color color;            // Material map color
    float value;            // Material map value
} MaterialMap;

// Material type (generic)
typedef struct Material {
    Shader shader;          // Material shader
    MaterialMap maps[12]; // Material maps
    float *params;          // Material generic parameters (if required)
} Material;

// Model type
typedef struct Model {
    Mesh mesh;              // Vertex data buffers (RAM and VRAM)
    Matrix transform;       // Local transform matrix
    Material material;      // Shader and textures data
} Model;

// Ray type (useful for raycast)
typedef struct Ray {
    Vector3 position;       // Ray position (origin)
    Vector3 direction;      // Ray direction
} Ray;

// Raycast hit information
typedef struct RayHitInfo {
    bool hit;               // Did the ray hit something?
    float distance;         // Distance to nearest hit
    Vector3 position;       // Position of nearest hit
    Vector3 normal;         // Surface normal of hit
} RayHitInfo;

// Wave type, defines audio wave data
typedef struct Wave {
    unsigned int sampleCount;   // Number of samples
    unsigned int sampleRate;    // Frequency (samples per second)
    unsigned int sampleSize;    // Bit depth (bits per sample): 8, 16, 32 (24 not supported)
    unsigned int channels;      // Number of channels (1-mono, 2-stereo)
    void *data;                 // Buffer data pointer
} Wave;

// Sound source type
typedef struct Sound {
    void *audioBuffer;      // Pointer to internal data used by the audio system

    unsigned int source;    // Audio source id
    unsigned int buffer;    // Audio buffer id
    int format;             // Audio format specifier
} Sound;

// Music type (file streaming from memory)
// NOTE: Anything longer than ~10 seconds should be streamed
typedef struct MusicData *Music;

// Audio stream type
// NOTE: Useful to create custom audio streams not bound to a specific file
typedef struct AudioStream {
    unsigned int sampleRate;    // Frequency (samples per second)
    unsigned int sampleSize;    // Bit depth (bits per sample): 8, 16, 32 (24 not supported)
    unsigned int channels;      // Number of channels (1-mono, 2-stereo)

    void *audioBuffer;          // Pointer to internal data used by the audio system.

    int format;                 // Audio format specifier
    unsigned int source;        // Audio source id
    unsigned int buffers[2];    // Audio buffers (double buffering)
} AudioStream;

// Head-Mounted-Display device parameters
typedef struct VrDeviceInfo {
    int hResolution;                // HMD horizontal resolution in pixels
    int vResolution;                // HMD vertical resolution in pixels
    float hScreenSize;              // HMD horizontal size in meters
    float vScreenSize;              // HMD vertical size in meters
    float vScreenCenter;            // HMD screen center in meters
    float eyeToScreenDistance;      // HMD distance between eye and display in meters
    float lensSeparationDistance;   // HMD lens separation distance in meters
    float interpupillaryDistance;   // HMD IPD (distance between pupils) in meters
    float lensDistortionValues[4];  // HMD lens distortion constant parameters
    float chromaAbCorrection[4];    // HMD chromatic aberration correction parameters
} VrDeviceInfo;

//----------------------------------------------------------------------------------
// Enumerators Definition
//----------------------------------------------------------------------------------
// Trace log type
typedef enum {
    LOG_INFO    = 1,
    LOG_WARNING = 2,
    LOG_ERROR   = 4,
    LOG_DEBUG   = 8,
    LOG_OTHER   = 16
} LogType;

// Shader location point type
typedef enum {
    LOC_VERTEX_POSITION = 0,
    LOC_VERTEX_TEXCOORD01,
    LOC_VERTEX_TEXCOORD02,
    LOC_VERTEX_NORMAL,
    LOC_VERTEX_TANGENT,
    LOC_VERTEX_COLOR,
    LOC_MATRIX_MVP,
    LOC_MATRIX_MODEL,
    LOC_MATRIX_VIEW,
    LOC_MATRIX_PROJECTION,
    LOC_VECTOR_VIEW,
    LOC_COLOR_DIFFUSE,
    LOC_COLOR_SPECULAR,
    LOC_COLOR_AMBIENT,
    LOC_MAP_ALBEDO,          // LOC_MAP_DIFFUSE
    LOC_MAP_METALNESS,       // LOC_MAP_SPECULAR
    LOC_MAP_NORMAL,
    LOC_MAP_ROUGHNESS,
    LOC_MAP_OCCLUSION,
    LOC_MAP_EMISSION,
    LOC_MAP_HEIGHT,
    LOC_MAP_CUBEMAP,
    LOC_MAP_IRRADIANCE,
    LOC_MAP_PREFILTER,
    LOC_MAP_BRDF
} ShaderLocationIndex;


// Material map type
typedef enum {
    MAP_ALBEDO    = 0,       // MAP_DIFFUSE
    MAP_METALNESS = 1,       // MAP_SPECULAR
    MAP_NORMAL    = 2,
    MAP_ROUGHNESS = 3,
    MAP_OCCLUSION,
    MAP_EMISSION,
    MAP_HEIGHT,
    MAP_CUBEMAP,             // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_IRRADIANCE,          // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_PREFILTER,           // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_BRDF
} TexmapIndex;

// Pixel formats
// NOTE: Support depends on OpenGL version and platform
typedef enum {
    UNCOMPRESSED_GRAYSCALE = 1,     // 8 bit per pixel (no alpha)
    UNCOMPRESSED_GRAY_ALPHA,        // 8*2 bpp (2 channels)
    UNCOMPRESSED_R5G6B5,            // 16 bpp
    UNCOMPRESSED_R8G8B8,            // 24 bpp
    UNCOMPRESSED_R5G5B5A1,          // 16 bpp (1 bit alpha)
    UNCOMPRESSED_R4G4B4A4,          // 16 bpp (4 bit alpha)
    UNCOMPRESSED_R8G8B8A8,          // 32 bpp
    UNCOMPRESSED_R32,               // 32 bpp (1 channel - float)
    UNCOMPRESSED_R32G32B32,         // 32*3 bpp (3 channels - float)
    UNCOMPRESSED_R32G32B32A32,      // 32*4 bpp (4 channels - float)
    COMPRESSED_DXT1_RGB,            // 4 bpp (no alpha)
    COMPRESSED_DXT1_RGBA,           // 4 bpp (1 bit alpha)
    COMPRESSED_DXT3_RGBA,           // 8 bpp
    COMPRESSED_DXT5_RGBA,           // 8 bpp
    COMPRESSED_ETC1_RGB,            // 4 bpp
    COMPRESSED_ETC2_RGB,            // 4 bpp
    COMPRESSED_ETC2_EAC_RGBA,       // 8 bpp
    COMPRESSED_PVRT_RGB,            // 4 bpp
    COMPRESSED_PVRT_RGBA,           // 4 bpp
    COMPRESSED_ASTC_4x4_RGBA,       // 8 bpp
    COMPRESSED_ASTC_8x8_RGBA        // 2 bpp
} PixelFormat;

// Texture parameters: filter mode
// NOTE 1: Filtering considers mipmaps if available in the texture
// NOTE 2: Filter is accordingly set for minification and magnification
typedef enum {
    FILTER_POINT = 0,               // No filter, just pixel aproximation
    FILTER_BILINEAR,                // Linear filtering
    FILTER_TRILINEAR,               // Trilinear filtering (linear with mipmaps)
    FILTER_ANISOTROPIC_4X,          // Anisotropic filtering 4x
    FILTER_ANISOTROPIC_8X,          // Anisotropic filtering 8x
    FILTER_ANISOTROPIC_16X,         // Anisotropic filtering 16x
} TextureFilterMode;

// Texture parameters: wrap mode
typedef enum {
    WRAP_REPEAT = 0,
    WRAP_CLAMP,
    WRAP_MIRROR
} TextureWrapMode;

// Color blending modes (pre-defined)
typedef enum {
    BLEND_ALPHA = 0,
    BLEND_ADDITIVE,
    BLEND_MULTIPLIED
} BlendMode;

// Gestures type
// NOTE: It could be used as flags to enable only some gestures
typedef enum {
    GESTURE_NONE        = 0,
    GESTURE_TAP         = 1,
    GESTURE_DOUBLETAP   = 2,
    GESTURE_HOLD        = 4,
    GESTURE_DRAG        = 8,
    GESTURE_SWIPE_RIGHT = 16,
    GESTURE_SWIPE_LEFT  = 32,
    GESTURE_SWIPE_UP    = 64,
    GESTURE_SWIPE_DOWN  = 128,
    GESTURE_PINCH_IN    = 256,
    GESTURE_PINCH_OUT   = 512
} Gestures;

// Camera system modes
typedef enum {
    CAMERA_CUSTOM = 0,
    CAMERA_FREE,
    CAMERA_ORBITAL,
    CAMERA_FIRST_PERSON,
    CAMERA_THIRD_PERSON
} CameraMode;

// Camera projection modes
typedef enum {
    CAMERA_PERSPECTIVE = 0,
    CAMERA_ORTHOGRAPHIC
} CameraType;

// Head Mounted Display devices
typedef enum {
    HMD_DEFAULT_DEVICE = 0,
    HMD_OCULUS_RIFT_DK2,
    HMD_OCULUS_RIFT_CV1,
    HMD_OCULUS_GO,
    HMD_VALVE_HTC_VIVE,
    HMD_SONY_PSVR
} VrDeviceType;

//------------------------------------------------------------------------------------
// Global Variables Definition
//------------------------------------------------------------------------------------
// It's lonely here...

//------------------------------------------------------------------------------------
// Window and Graphics Device Functions (Module: core)
//------------------------------------------------------------------------------------

// Window-related functions
void InitWindow(int width, int height, const char *title);  // Initialize window and OpenGL context
void CloseWindow(void);                                     // Close window and unload OpenGL context
bool IsWindowReady(void);                                   // Check if window has been initialized successfully
bool WindowShouldClose(void);                               // Check if KEY_ESCAPE pressed or Close icon pressed
bool IsWindowMinimized(void);                               // Check if window has been minimized (or lost focus)
void ToggleFullscreen(void);                                // Toggle fullscreen mode (only PLATFORM_DESKTOP)
void SetWindowIcon(Image image);                            // Set icon for window (only PLATFORM_DESKTOP)
void SetWindowTitle(const char *title);                     // Set title for window (only PLATFORM_DESKTOP)
void SetWindowPosition(int x, int y);                       // Set window position on screen (only PLATFORM_DESKTOP)
void SetWindowMonitor(int monitor);                         // Set monitor for the current window (fullscreen mode)
void SetWindowMinSize(int width, int height);               // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
void SetWindowSize(int width, int height);                  // Set window dimensions
int GetScreenWidth(void);                                   // Get current screen width
int GetScreenHeight(void);                                  // Get current screen height

// Cursor-related functions
void ShowCursor(void);                                      // Shows cursor
void HideCursor(void);                                      // Hides cursor
bool IsCursorHidden(void);                                  // Check if cursor is not visible
void EnableCursor(void);                                    // Enables cursor (unlock cursor)
void DisableCursor(void);                                   // Disables cursor (lock cursor)

// Drawing-related functions
void ClearBackground(Color color);                          // Set background color (framebuffer clear color)
void BeginDrawing(void);                                    // Setup canvas (framebuffer) to start drawing
void EndDrawing(void);                                      // End canvas drawing and swap buffers (double buffering)
void BeginMode2D(Camera2D camera);                          // Initialize 2D mode with custom camera (2D)
void EndMode2D(void);                                       // Ends 2D mode with custom camera
void BeginMode3D(Camera3D camera);                          // Initializes 3D mode with custom camera (3D)
void EndMode3D(void);                                       // Ends 3D mode and returns to default 2D orthographic mode
void BeginTextureMode(RenderTexture2D target);              // Initializes render texture for drawing
void EndTextureMode(void);                                  // Ends drawing to render texture

// Screen-space-related functions
Ray GetMouseRay(Vector2 mousePosition, Camera3D camera);      // Returns a ray trace from mouse position
Vector2 GetWorldToScreen(Vector3 position, Camera3D camera);  // Returns the screen space position for a 3d world space position
Matrix GetCameraMatrix(Camera3D camera);                      // Returns camera transform matrix (view matrix)

// Timming-related functions
void SetTargetFPS(int fps);                                 // Set target FPS (maximum)
int GetFPS(void);                                           // Returns current FPS
float GetFrameTime(void);                                   // Returns time in seconds for last frame drawn
double GetTime(void);                                       // Returns elapsed time in seconds since InitWindow()

// Color-related functions
int ColorToInt(Color color);                                // Returns hexadecimal value for a Color
Vector4 ColorNormalize(Color color);                        // Returns color normalized as float [0..1]
Vector3 ColorToHSV(Color color);                            // Returns HSV values for a Color
Color GetColor(int hexValue);                               // Returns a Color struct from hexadecimal value
Color Fade(Color color, float alpha);                       // Color fade-in or fade-out, alpha goes from 0.0f to 1.0f

// Misc. functions
void ShowLogo(void);                                        // Activate raylib logo at startup (can be done with flags)
void SetConfigFlags(unsigned char flags);                   // Setup window configuration flags (view FLAGS)
void SetTraceLog(unsigned char types);                      // Enable trace log message types (bit flags based)
void TraceLog(int logType, const char *text, ...);          // Show trace log messages (LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_DEBUG)
void TakeScreenshot(const char *fileName);                  // Takes a screenshot of current screen (saved a .png)
int GetRandomValue(int min, int max);                       // Returns a random value between min and max (both included)

// Files management functions
bool IsFileExtension(const char *fileName, const char *ext);// Check file extension
const char *GetExtension(const char *fileName);             // Get pointer to extension for a filename string
const char *GetFileName(const char *filePath);              // Get pointer to filename for a path string
const char *GetDirectoryPath(const char *fileName);         // Get full path for a given fileName (uses static string)
const char *GetWorkingDirectory(void);                      // Get current working directory (uses static string)
bool ChangeDirectory(const char *dir);                      // Change working directory, returns true if success
bool IsFileDropped(void);                                   // Check if a file has been dropped into window
char **GetDroppedFiles(int *count);                         // Get dropped files names
void ClearDroppedFiles(void);                               // Clear dropped files paths buffer

// Persistent storage management
void StorageSaveValue(int position, int value);             // Save integer value to storage file (to defined position)
int StorageLoadValue(int position);                         // Load integer value from storage file (from defined position)

//------------------------------------------------------------------------------------
// Input Handling Functions (Module: core)
//------------------------------------------------------------------------------------

// Input-related functions: keyboard
bool IsKeyPressed(int key);                             // Detect if a key has been pressed once
bool IsKeyDown(int key);                                // Detect if a key is being pressed
bool IsKeyReleased(int key);                            // Detect if a key has been released once
bool IsKeyUp(int key);                                  // Detect if a key is NOT being pressed
int GetKeyPressed(void);                                // Get latest key pressed
void SetExitKey(int key);                               // Set a custom key to exit program (default is ESC)

// Input-related functions: gamepads
bool IsGamepadAvailable(int gamepad);                   // Detect if a gamepad is available
bool IsGamepadName(int gamepad, const char *name);      // Check gamepad name (if available)
const char *GetGamepadName(int gamepad);                // Return gamepad internal name id
bool IsGamepadButtonPressed(int gamepad, int button);   // Detect if a gamepad button has been pressed once
bool IsGamepadButtonDown(int gamepad, int button);      // Detect if a gamepad button is being pressed
bool IsGamepadButtonReleased(int gamepad, int button);  // Detect if a gamepad button has been released once
bool IsGamepadButtonUp(int gamepad, int button);        // Detect if a gamepad button is NOT being pressed
int GetGamepadButtonPressed(void);                      // Get the last gamepad button pressed
int GetGamepadAxisCount(int gamepad);                   // Return gamepad axis count for a gamepad
float GetGamepadAxisMovement(int gamepad, int axis);    // Return axis movement value for a gamepad axis

// Input-related functions: mouse
bool IsMouseButtonPressed(int button);                  // Detect if a mouse button has been pressed once
bool IsMouseButtonDown(int button);                     // Detect if a mouse button is being pressed
bool IsMouseButtonReleased(int button);                 // Detect if a mouse button has been released once
bool IsMouseButtonUp(int button);                       // Detect if a mouse button is NOT being pressed
int GetMouseX(void);                                    // Returns mouse position X
int GetMouseY(void);                                    // Returns mouse position Y
Vector2 GetMousePosition(void);                         // Returns mouse position XY
void SetMousePosition(Vector2 position);                // Set mouse position XY
void SetMouseScale(float scale);                        // Set mouse scaling
int GetMouseWheelMove(void);                            // Returns mouse wheel movement Y

// Input-related functions: touch
int GetTouchX(void);                                    // Returns touch position X for touch point 0 (relative to screen size)
int GetTouchY(void);                                    // Returns touch position Y for touch point 0 (relative to screen size)
Vector2 GetTouchPosition(int index);                    // Returns touch position XY for a touch point index (relative to screen size)

//------------------------------------------------------------------------------------
// Gestures and Touch Handling Functions (Module: gestures)
//------------------------------------------------------------------------------------
void SetGesturesEnabled(unsigned int gestureFlags);     // Enable a set of gestures using flags
bool IsGestureDetected(int gesture);                    // Check if a gesture have been detected
int GetGestureDetected(void);                           // Get latest detected gesture
int GetTouchPointsCount(void);                          // Get touch points count
float GetGestureHoldDuration(void);                     // Get gesture hold time in milliseconds
Vector2 GetGestureDragVector(void);                     // Get gesture drag vector
float GetGestureDragAngle(void);                        // Get gesture drag angle
Vector2 GetGesturePinchVector(void);                    // Get gesture pinch delta
float GetGesturePinchAngle(void);                       // Get gesture pinch angle

//------------------------------------------------------------------------------------
// Camera System Functions (Module: camera)
//------------------------------------------------------------------------------------
void SetCameraMode(Camera3D camera, int mode);              // Set camera mode (multiple camera modes available)
void UpdateCamera(Camera3D *camera);                        // Update camera position for selected mode

void SetCameraPanControl(int panKey);                       // Set camera pan key to combine with mouse movement (free camera)
void SetCameraAltControl(int altKey);                       // Set camera alt key to combine with mouse movement (free camera)
void SetCameraSmoothZoomControl(int szKey);                 // Set camera smooth zoom key to combine with mouse (free camera)
void SetCameraMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey); // Set camera move controls (1st person and 3rd person cameras)

//------------------------------------------------------------------------------------
// Basic Shapes Drawing Functions (Module: shapes)
//------------------------------------------------------------------------------------

// Basic shapes drawing functions
void DrawPixel(int posX, int posY, Color color);                                                   // Draw a pixel
void DrawPixelV(Vector2 position, Color color);                                                    // Draw a pixel (Vector version)
void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);                // Draw a line
void DrawLineV(Vector2 startPos, Vector2 endPos, Color color);                                     // Draw a line (Vector version)
void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);                       // Draw a line defining thickness
void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);                   // Draw a line using cubic-bezier curves in-out
void DrawCircle(int centerX, int centerY, float radius, Color color);                              // Draw a color-filled circle
void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2);       // Draw a gradient-filled circle
void DrawCircleV(Vector2 center, float radius, Color color);                                       // Draw a color-filled circle (Vector version)
void DrawCircleLines(int centerX, int centerY, float radius, Color color);                         // Draw circle outline
void DrawRectangle(int posX, int posY, int width, int height, Color color);                        // Draw a color-filled rectangle
void DrawRectangleV(Vector2 position, Vector2 size, Color color);                                  // Draw a color-filled rectangle (Vector version)
void DrawRectangleRec(Rectangle rec, Color color);                                                 // Draw a color-filled rectangle
void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);                 // Draw a color-filled rectangle with pro parameters
void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2);// Draw a vertical-gradient-filled rectangle
void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2);// Draw a horizontal-gradient-filled rectangle
void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);       // Draw a gradient-filled rectangle with custom vertex colors
void DrawRectangleLines(int posX, int posY, int width, int height, Color color);                   // Draw rectangle outline
void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color);                              // Draw rectangle outline with extended parameters
void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                                // Draw a color-filled triangle
void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                           // Draw triangle outline
void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);               // Draw a regular polygon (Vector version)
void DrawPolyEx(Vector2 *points, int numPoints, Color color);                                      // Draw a closed polygon defined by points
void DrawPolyExLines(Vector2 *points, int numPoints, Color color);                                 // Draw polygon lines

// Basic shapes collision detection functions
bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                                           // Check collision between two rectangles
bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);        // Check collision between two circles
bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);                         // Check collision between circle and rectangle
Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2);                                         // Get collision rectangle for two rectangles collision
bool CheckCollisionPointRec(Vector2 point, Rectangle rec);                                         // Check if point is inside rectangle
bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);                       // Check if point is inside circle
bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);               // Check if point is inside a triangle

//------------------------------------------------------------------------------------
// Texture Loading and Drawing Functions (Module: textures)
//------------------------------------------------------------------------------------

// Image/Texture2D data loading/unloading/saving functions
Image LoadImage(const char *fileName);                                                             // Load image from file into CPU memory (RAM)
Image LoadImageEx(Color *pixels, int width, int height);                                           // Load image from Color array data (RGBA - 32bit)
Image LoadImagePro(void *data, int width, int height, int format);                                 // Load image from raw data with parameters
Image LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);       // Load image from RAW file data
void ExportImage(const char *fileName, Image image);                                               // Export image as a PNG file
Texture2D LoadTexture(const char *fileName);                                                       // Load texture from file into GPU memory (VRAM)
Texture2D LoadTextureFromImage(Image image);                                                       // Load texture from image data
RenderTexture2D LoadRenderTexture(int width, int height);                                          // Load texture for rendering (framebuffer)
void UnloadImage(Image image);                                                                     // Unload image from CPU memory (RAM)
void UnloadTexture(Texture2D texture);                                                             // Unload texture from GPU memory (VRAM)
void UnloadRenderTexture(RenderTexture2D target);                                                  // Unload render texture from GPU memory (VRAM)
Color *GetImageData(Image image);                                                                  // Get pixel data from image as a Color struct array
Vector4 *GetImageDataNormalized(Image image);                                                      // Get pixel data from image as Vector4 array (float normalized)
int GetPixelDataSize(int width, int height, int format);                                           // Get pixel data size in bytes (image or texture)
Image GetTextureData(Texture2D texture);                                                           // Get pixel data from GPU texture and return an Image
void UpdateTexture(Texture2D texture, const void *pixels);                                         // Update GPU texture with new data

// Image manipulation functions
Image ImageCopy(Image image);                                                                      // Create an image duplicate (useful for transformations)
void ImageToPOT(Image *image, Color fillColor);                                                    // Convert image to POT (power-of-two)
void ImageFormat(Image *image, int newFormat);                                                     // Convert image data to desired format
void ImageAlphaMask(Image *image, Image alphaMask);                                                // Apply alpha mask to image
void ImageAlphaClear(Image *image, Color color, float threshold);                                  // Clear alpha channel to desired color
void ImageAlphaCrop(Image *image, float threshold);                                                // Crop image depending on alpha value
void ImageAlphaPremultiply(Image *image);                                                          // Premultiply alpha channel
void ImageCrop(Image *image, Rectangle crop);                                                      // Crop an image to a defined rectangle
void ImageResize(Image *image, int newWidth, int newHeight);                                       // Resize image (bilinear filtering)
void ImageResizeNN(Image *image, int newWidth,int newHeight);                                      // Resize image (Nearest-Neighbor scaling algorithm)
void ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color color);  // Resize canvas and fill with color
void ImageMipmaps(Image *image);                                                                   // Generate all mipmap levels for a provided image
void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
Image ImageText(const char *text, int fontSize, Color color);                                      // Create an image from text (default font)
Image ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);         // Create an image from text (custom sprite font)
void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec);                         // Draw a source image within a destination image
void ImageDrawRectangle(Image *dst, Vector2 position, Rectangle rec, Color color);                 // Draw rectangle within an image
void ImageDrawText(Image *dst, Vector2 position, const char *text, int fontSize, Color color);     // Draw text (default font) within an image (destination)
void ImageDrawTextEx(Image *dst, Vector2 position, Font font, const char *text, float fontSize, float spacing, Color color); // Draw text (custom sprite font) within an image (destination)
void ImageFlipVertical(Image *image);                                                              // Flip image vertically
void ImageFlipHorizontal(Image *image);                                                            // Flip image horizontally
void ImageRotateCW(Image *image);                                                                  // Rotate image clockwise 90deg
void ImageRotateCCW(Image *image);                                                                 // Rotate image counter-clockwise 90deg
void ImageColorTint(Image *image, Color color);                                                    // Modify image color: tint
void ImageColorInvert(Image *image);                                                               // Modify image color: invert
void ImageColorGrayscale(Image *image);                                                            // Modify image color: grayscale
void ImageColorContrast(Image *image, float contrast);                                             // Modify image color: contrast (-100 to 100)
void ImageColorBrightness(Image *image, int brightness);                                           // Modify image color: brightness (-255 to 255)
void ImageColorReplace(Image *image, Color color, Color replace);                                  // Modify image color: replace color

// Image generation functions
Image GenImageColor(int width, int height, Color color);                                           // Generate image: plain color
Image GenImageGradientV(int width, int height, Color top, Color bottom);                           // Generate image: vertical gradient
Image GenImageGradientH(int width, int height, Color left, Color right);                           // Generate image: horizontal gradient
Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);      // Generate image: radial gradient
Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);    // Generate image: checked
Image GenImageWhiteNoise(int width, int height, float factor);                                     // Generate image: white noise
Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);           // Generate image: perlin noise
Image GenImageCellular(int width, int height, int tileSize);                                       // Generate image: cellular algorithm. Bigger tileSize means bigger cells

// Texture2D configuration functions
void GenTextureMipmaps(Texture2D *texture);                                                        // Generate GPU mipmaps for a texture
void SetTextureFilter(Texture2D texture, int filterMode);                                          // Set texture scaling filter mode
void SetTextureWrap(Texture2D texture, int wrapMode);                                              // Set texture wrapping mode

// Texture2D drawing functions
void DrawTexture(Texture2D texture, int posX, int posY, Color tint);                               // Draw a Texture2D
void DrawTextureV(Texture2D texture, Vector2 position, Color tint);                                // Draw a Texture2D with position defined as Vector2
void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);  // Draw a Texture2D with extended parameters
void DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint);         // Draw a part of a texture defined by a rectangle
void DrawTexturePro(Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint); // Draw a part of a texture defined by a rectangle with 'pro' parameters

//------------------------------------------------------------------------------------
// Font Loading and Text Drawing Functions (Module: text)
//------------------------------------------------------------------------------------

// Font loading/unloading functions
Font GetFontDefault(void);                                                            // Get the default Font
Font LoadFont(const char *fileName);                                                  // Load font from file into GPU memory (VRAM)
Font LoadFontEx(const char *fileName, int fontSize, int charsCount, int *fontChars);  // Load font from file with extended parameters
CharInfo *LoadFontData(const char *fileName, int fontSize, int *fontChars, int charsCount, bool sdf); // Load font data for further use
Image GenImageFontAtlas(CharInfo *chars, int fontSize, int charsCount, int padding, int packMethod);  // Generate image font atlas using chars info
void UnloadFont(Font font);                                                           // Unload Font from GPU memory (VRAM)

// Text drawing functions
void DrawFPS(int posX, int posY);                                                     // Shows current FPS
void DrawText(const char *text, int posX, int posY, int fontSize, Color color);       // Draw text (using default font)
void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text using font and additional parameters

// Text misc. functions
int MeasureText(const char *text, int fontSize);                                      // Measure string width for default font
Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);    // Measure string size for Font
const char *FormatText(const char *text, ...);                                        // Formatting of text with variables to 'embed'
const char *SubText(const char *text, int position, int length);                      // Get a piece of a text string
int GetGlyphIndex(Font font, int character);                                          // Get index position for a unicode character on font

//------------------------------------------------------------------------------------
// Basic 3d Shapes Drawing Functions (Module: models)
//------------------------------------------------------------------------------------

// Basic geometric 3D shapes drawing functions
void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);                                    // Draw a line in 3D world space
void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color); // Draw a circle in 3D world space
void DrawCube(Vector3 position, float width, float height, float length, Color color);             // Draw cube
void DrawCubeV(Vector3 position, Vector3 size, Color color);                                       // Draw cube (Vector version)
void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);        // Draw cube wires
void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured
void DrawSphere(Vector3 centerPos, float radius, Color color);                                     // Draw sphere
void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);            // Draw sphere with extended parameters
void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);         // Draw sphere wires
void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone
void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone wires
void DrawPlane(Vector3 centerPos, Vector2 size, Color color);                                      // Draw a plane XZ
void DrawRay(Ray ray, Color color);                                                                // Draw a ray line
void DrawGrid(int slices, float spacing);                                                          // Draw a grid (centered at (0, 0, 0))
void DrawGizmo(Vector3 position);                                                                  // Draw simple gizmo
//DrawTorus(), DrawTeapot() could be useful?

//------------------------------------------------------------------------------------
// Model 3d Loading and Drawing Functions (Module: models)
//------------------------------------------------------------------------------------

// Model loading/unloading functions
Model LoadModel(const char *fileName);                                                            // Load model from files (mesh and material)
Model LoadModelFromMesh(Mesh mesh);                                                               // Load model from generated mesh
void UnloadModel(Model model);                                                                    // Unload model from memory (RAM and/or VRAM)

// Mesh loading/unloading functions
Mesh LoadMesh(const char *fileName);                                                              // Load mesh from file
void UnloadMesh(Mesh *mesh);                                                                      // Unload mesh from memory (RAM and/or VRAM)
void ExportMesh(const char *fileName, Mesh mesh);                                                 // Export mesh as an OBJ file

// Mesh manipulation functions
BoundingBox MeshBoundingBox(Mesh mesh);                                                           // Compute mesh bounding box limits
void MeshTangents(Mesh *mesh);                                                                    // Compute mesh tangents
void MeshBinormals(Mesh *mesh);                                                                   // Compute mesh binormals

// Mesh generation functions
Mesh GenMeshPlane(float width, float length, int resX, int resZ);                                 // Generate plane mesh (with subdivisions)
Mesh GenMeshCube(float width, float height, float length);                                        // Generate cuboid mesh
Mesh GenMeshSphere(float radius, int rings, int slices);                                          // Generate sphere mesh (standard sphere)
Mesh GenMeshHemiSphere(float radius, int rings, int slices);                                      // Generate half-sphere mesh (no bottom cap)
Mesh GenMeshCylinder(float radius, float height, int slices);                                     // Generate cylinder mesh
Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);                               // Generate torus mesh
Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);                                // Generate trefoil knot mesh
Mesh GenMeshHeightmap(Image heightmap, Vector3 size);                                             // Generate heightmap mesh from image data
Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);                                           // Generate cubes-based map mesh from image data

// Material loading/unloading functions
Material LoadMaterial(const char *fileName);                                                      // Load material from file
Material LoadMaterialDefault(void);                                                               // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
void UnloadMaterial(Material material);                                                           // Unload material from GPU memory (VRAM)

// Model drawing functions
void DrawModel(Model model, Vector3 position, float scale, Color tint);                           // Draw a model (with texture if set)
void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model with extended parameters
void DrawModelWires(Model model, Vector3 position, float scale, Color tint);                      // Draw a model wires (with texture if set)
void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model wires (with texture if set) with extended parameters
void DrawBoundingBox(BoundingBox box, Color color);                                               // Draw bounding box (wires)
void DrawBillboard(Camera3D camera, Texture2D texture, Vector3 center, float size, Color tint);   // Draw a billboard texture
void DrawBillboardRec(Camera3D camera, Texture2D texture, Rectangle sourceRec, Vector3 center, float size, Color tint); // Draw a billboard texture defined by sourceRec

// Collision detection functions
bool CheckCollisionSpheres(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB);       // Detect collision between two spheres
bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                     // Detect collision between two bounding boxes
bool CheckCollisionBoxSphere(BoundingBox box, Vector3 centerSphere, float radiusSphere);          // Detect collision between box and sphere
bool CheckCollisionRaySphere(Ray ray, Vector3 spherePosition, float sphereRadius);                // Detect collision between ray and sphere
bool CheckCollisionRaySphereEx(Ray ray, Vector3 spherePosition, float sphereRadius, Vector3 *collisionPoint); // Detect collision between ray and sphere, returns collision point
bool CheckCollisionRayBox(Ray ray, BoundingBox box);                                              // Detect collision between ray and box
RayHitInfo GetCollisionRayModel(Ray ray, Model *model);                                           // Get collision info between ray and model
RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                  // Get collision info between ray and triangle
RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight);                                    // Get collision info between ray and ground plane (Y-normal plane)

//------------------------------------------------------------------------------------
// Shaders System Functions (Module: rlgl)
// NOTE: This functions are useless when using OpenGL 1.1
//------------------------------------------------------------------------------------

// Shader loading/unloading functions
char *LoadText(const char *fileName);                               // Load chars array from text file
Shader LoadShader(const char *vsFileName, const char *fsFileName);  // Load shader from files and bind default locations
Shader LoadShaderCode(char *vsCode, char *fsCode);                  // Load shader from code strings and bind default locations
void UnloadShader(Shader shader);                                   // Unload shader from GPU memory (VRAM)

Shader GetShaderDefault(void);                                      // Get default shader
Texture2D GetTextureDefault(void);                                  // Get default texture

// Shader configuration functions
int GetShaderLocation(Shader shader, const char *uniformName);              // Get shader uniform location
void SetShaderValue(Shader shader, int uniformLoc, const float *value, int size); // Set shader uniform value (float)
void SetShaderValuei(Shader shader, int uniformLoc, const int *value, int size);  // Set shader uniform value (int)
void SetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat);       // Set shader uniform value (matrix 4x4)
void SetMatrixProjection(Matrix proj);                              // Set a custom projection matrix (replaces internal projection matrix)
void SetMatrixModelview(Matrix view);                               // Set a custom modelview matrix (replaces internal modelview matrix)
Matrix GetMatrixModelview();                                        // Get internal modelview matrix

// Texture maps generation (PBR)
// NOTE: Required shaders should be provided
Texture2D GenTextureCubemap(Shader shader, Texture2D skyHDR, int size);       // Generate cubemap texture from HDR texture
Texture2D GenTextureIrradiance(Shader shader, Texture2D cubemap, int size);   // Generate irradiance texture using cubemap data
Texture2D GenTexturePrefilter(Shader shader, Texture2D cubemap, int size);    // Generate prefilter texture using cubemap data
Texture2D GenTextureBRDF(Shader shader, Texture2D cubemap, int size);         // Generate BRDF texture using cubemap data

// Shading begin/end functions
void BeginShaderMode(Shader shader);                                // Begin custom shader drawing
void EndShaderMode(void);                                           // End custom shader drawing (use default shader)
void BeginBlendMode(int mode);                                      // Begin blending mode (alpha, additive, multiplied)
void EndBlendMode(void);                                            // End blending mode (reset to default: alpha blending)

// VR control functions
VrDeviceInfo GetVrDeviceInfo(int vrDeviceType);   // Get VR device information for some standard devices
void InitVrSimulator(VrDeviceInfo info);          // Init VR simulator for selected device parameters
void CloseVrSimulator(void);                      // Close VR simulator for current device
bool IsVrSimulatorReady(void);                    // Detect if VR simulator is ready
void SetVrDistortionShader(Shader shader);        // Set VR distortion shader for stereoscopic rendering
void UpdateVrTracking(Camera3D *camera);          // Update VR tracking (position and orientation) and camera
void ToggleVrMode(void);                          // Enable/Disable VR experience
void BeginVrDrawing(void);                        // Begin VR simulator stereo rendering
void EndVrDrawing(void);                          // End VR simulator stereo rendering

//------------------------------------------------------------------------------------
// Audio Loading and Playing Functions (Module: audio)
//------------------------------------------------------------------------------------

// Audio device management functions
void InitAudioDevice(void);                                     // Initialize audio device and context
void CloseAudioDevice(void);                                    // Close the audio device and context
bool IsAudioDeviceReady(void);                                  // Check if audio device has been initialized successfully
void SetMasterVolume(float volume);                             // Set master volume (listener)

// Wave/Sound loading/unloading functions
Wave LoadWave(const char *fileName);                            // Load wave data from file
Wave LoadWaveEx(void *data, int sampleCount, int sampleRate, int sampleSize, int channels); // Load wave data from raw array data
Sound LoadSound(const char *fileName);                          // Load sound from file
Sound LoadSoundFromWave(Wave wave);                             // Load sound from wave data
void UpdateSound(Sound sound, const void *data, int samplesCount);// Update sound buffer with new data
void UnloadWave(Wave wave);                                     // Unload wave data
void UnloadSound(Sound sound);                                  // Unload sound

// Wave/Sound management functions
void PlaySound(Sound sound);                                    // Play a sound
void PauseSound(Sound sound);                                   // Pause a sound
void ResumeSound(Sound sound);                                  // Resume a paused sound
void StopSound(Sound sound);                                    // Stop playing a sound
bool IsSoundPlaying(Sound sound);                               // Check if a sound is currently playing
void SetSoundVolume(Sound sound, float volume);                 // Set volume for a sound (1.0 is max level)
void SetSoundPitch(Sound sound, float pitch);                   // Set pitch for a sound (1.0 is base level)
void WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels);  // Convert wave data to desired format
Wave WaveCopy(Wave wave);                                       // Copy a wave to a new wave
void WaveCrop(Wave *wave, int initSample, int finalSample);     // Crop a wave to defined samples range
float *GetWaveData(Wave wave);                                  // Get samples data from wave as a floats array

// Music management functions
Music LoadMusicStream(const char *fileName);                    // Load music stream from file
void UnloadMusicStream(Music music);                            // Unload music stream
void PlayMusicStream(Music music);                              // Start music playing
void UpdateMusicStream(Music music);                            // Updates buffers for music streaming
void StopMusicStream(Music music);                              // Stop music playing
void PauseMusicStream(Music music);                             // Pause music playing
void ResumeMusicStream(Music music);                            // Resume playing paused music
bool IsMusicPlaying(Music music);                               // Check if music is playing
void SetMusicVolume(Music music, float volume);                 // Set volume for music (1.0 is max level)
void SetMusicPitch(Music music, float pitch);                   // Set pitch for a music (1.0 is base level)
void SetMusicLoopCount(Music music, int count);                 // Set music loop count (loop repeats)
float GetMusicTimeLength(Music music);                          // Get music time length (in seconds)
float GetMusicTimePlayed(Music music);                          // Get current music time played (in seconds)

// AudioStream management functions
AudioStream InitAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels); // Init audio stream (to stream raw audio pcm data)
void UpdateAudioStream(AudioStream stream, const void *data, int samplesCount); // Update audio stream buffers with data
void CloseAudioStream(AudioStream stream);                      // Close audio stream and free memory
bool IsAudioBufferProcessed(AudioStream stream);                // Check if any audio stream buffers requires refill
void PlayAudioStream(AudioStream stream);                       // Play audio stream
void PauseAudioStream(AudioStream stream);                      // Pause audio stream
void ResumeAudioStream(AudioStream stream);                     // Resume audio stream
bool IsAudioStreamPlaying(AudioStream stream);                  // Check if audio stream is playing
void StopAudioStream(AudioStream stream);                       // Stop audio stream
void SetAudioStreamVolume(AudioStream stream, float volume);    // Set volume for audio stream (1.0 is max level)
void SetAudioStreamPitch(AudioStream stream, float pitch);      // Set pitch for audio stream (1.0 is base level)
