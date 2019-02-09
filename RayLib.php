<?php

class RayLib
{
    const PI = 3.14159265358979323846;

    const MAX_TOUCH_POINTS = 10;      // Maximum number of touch points supported

    // Shader and material limits
    const MAX_SHADER_LOCATIONS = 32;      // Maximum number of predefined locations stored in shader struct
    const MAX_MATERIAL_MAPS    = 12;      // Maximum number of texture maps stored in shader struct

    //----------------------------------------------------------------------------------
    // Enumerators Definition
    //----------------------------------------------------------------------------------

    // System config flags
    const FLAG_SHOW_LOGO          = 1;    // Set to show raylib logo at startup
    const FLAG_FULLSCREEN_MODE    = 2;    // Set to run program in fullscreen
    const FLAG_WINDOW_RESIZABLE   = 4;    // Set to allow resizable window
    const FLAG_WINDOW_UNDECORATED = 8;    // Set to disable window decoration (frame and buttons)
    const FLAG_WINDOW_TRANSPARENT = 16;   // Set to allow transparent window
    const FLAG_WINDOW_HIDDEN      = 128;  // Set to create the window initially hidden
    const FLAG_MSAA_4X_HINT       = 32;   // Set to try enabling MSAA 4X
    const FLAG_VSYNC_HINT         = 64;   // Set to try enabling V-Sync on GPU

    // Trace log type
    const LOG_ALL     = 0;        // Display all logs
    const LOG_TRACE   = 1;
    const LOG_DEBUG   = 2;
    const LOG_INFO    = 3;
    const LOG_WARNING = 4;
    const LOG_ERROR   = 5;
    const LOG_FATAL   = 6;
    const LOG_NONE    = 7;        // Disable logging

    // Keyboard keys
    // Alphanumeric keys
    const KEY_APOSTROPHE      = 39;
    const KEY_COMMA           = 44;
    const KEY_MINUS           = 45;
    const KEY_PERIOD          = 46;
    const KEY_SLASH           = 47;
    const KEY_ZERO            = 48;
    const KEY_ONE             = 49;
    const KEY_TWO             = 50;
    const KEY_THREE           = 51;
    const KEY_FOUR            = 52;
    const KEY_FIVE            = 53;
    const KEY_SIX             = 54;
    const KEY_SEVEN           = 55;
    const KEY_EIGHT           = 56;
    const KEY_NINE            = 57;
    const KEY_SEMICOLON       = 59;
    const KEY_EQUAL           = 61;
    const KEY_A               = 65;
    const KEY_B               = 66;
    const KEY_C               = 67;
    const KEY_D               = 68;
    const KEY_E               = 69;
    const KEY_F               = 70;
    const KEY_G               = 71;
    const KEY_H               = 72;
    const KEY_I               = 73;
    const KEY_J               = 74;
    const KEY_K               = 75;
    const KEY_L               = 76;
    const KEY_M               = 77;
    const KEY_N               = 78;
    const KEY_O               = 79;
    const KEY_P               = 80;
    const KEY_Q               = 81;
    const KEY_R               = 82;
    const KEY_S               = 83;
    const KEY_T               = 84;
    const KEY_U               = 85;
    const KEY_V               = 86;
    const KEY_W               = 87;
    const KEY_X               = 88;
    const KEY_Y               = 89;
    const KEY_Z               = 90;

    // Function keys
    const KEY_SPACE           = 32;
    const KEY_ESCAPE          = 256;
    const KEY_ENTER           = 257;
    const KEY_TAB             = 258;
    const KEY_BACKSPACE       = 259;
    const KEY_INSERT          = 260;
    const KEY_DELETE          = 261;
    const KEY_RIGHT           = 262;
    const KEY_LEFT            = 263;
    const KEY_DOWN            = 264;
    const KEY_UP              = 265;
    const KEY_PAGE_UP         = 266;
    const KEY_PAGE_DOWN       = 267;
    const KEY_HOME            = 268;
    const KEY_END             = 269;
    const KEY_CAPS_LOCK       = 280;
    const KEY_SCROLL_LOCK     = 281;
    const KEY_NUM_LOCK        = 282;
    const KEY_PRINT_SCREEN    = 283;
    const KEY_PAUSE           = 284;
    const KEY_F1              = 290;
    const KEY_F2              = 291;
    const KEY_F3              = 292;
    const KEY_F4              = 293;
    const KEY_F5              = 294;
    const KEY_F6              = 295;
    const KEY_F7              = 296;
    const KEY_F8              = 297;
    const KEY_F9              = 298;
    const KEY_F10             = 299;
    const KEY_F11             = 300;
    const KEY_F12             = 301;
    const KEY_LEFT_SHIFT      = 340;
    const KEY_LEFT_CONTROL    = 341;
    const KEY_LEFT_ALT        = 342;
    const KEY_LEFT_SUPER      = 343;
    const KEY_RIGHT_SHIFT     = 344;
    const KEY_RIGHT_CONTROL   = 345;
    const KEY_RIGHT_ALT       = 346;
    const KEY_RIGHT_SUPER     = 347;
    const KEY_KB_MENU         = 348;
    const KEY_LEFT_BRACKET    = 91;
    const KEY_BACKSLASH       = 92;
    const KEY_RIGHT_BRACKET   = 93;
    const KEY_GRAVE           = 96;

    // Keypad keys
    const KEY_KP_0            = 320;
    const KEY_KP_1            = 321;
    const KEY_KP_2            = 322;
    const KEY_KP_3            = 323;
    const KEY_KP_4            = 324;
    const KEY_KP_5            = 325;
    const KEY_KP_6            = 326;
    const KEY_KP_7            = 327;
    const KEY_KP_8            = 328;
    const KEY_KP_9            = 329;
    const KEY_KP_DECIMAL      = 330;
    const KEY_KP_DIVIDE       = 331;
    const KEY_KP_MULTIPLY     = 332;
    const KEY_KP_SUBTRACT     = 333;
    const KEY_KP_ADD          = 334;
    const KEY_KP_ENTER        = 335;
    const KEY_KP_EQUAL        = 336;

    // Android buttons
    const KEY_BACK            = 4;
    const KEY_MENU            = 82;
    const KEY_VOLUME_UP       = 24;
    const KEY_VOLUME_DOWN     = 25;

    // Mouse buttons
    const MOUSE_LEFT_BUTTON   = 0;
    const MOUSE_RIGHT_BUTTON  = 1;
    const MOUSE_MIDDLE_BUTTON = 2;

    // Not included:
    // Gamepad number
    // PS3 USB Controller Buttons
    // PS3 USB Controller Axis
    // Xbox360 USB Controller Buttons
    // Xbox360 USB Controller Axis
    // Android Gamepad Controller (SNES CLASSIC)

    // Shader location point type
    const LOC_VERTEX_POSITION   = 0;
    const LOC_VERTEX_TEXCOORD01 = 1;
    const LOC_VERTEX_TEXCOORD02 = 2;
    const LOC_VERTEX_NORMAL     = 3;
    const LOC_VERTEX_TANGENT    = 4;
    const LOC_VERTEX_COLOR      = 5;
    const LOC_MATRIX_MVP        = 6;
    const LOC_MATRIX_MODEL      = 7;
    const LOC_MATRIX_VIEW       = 8;
    const LOC_MATRIX_PROJECTION = 9;
    const LOC_VECTOR_VIEW       = 10;
    const LOC_COLOR_DIFFUSE     = 11;
    const LOC_COLOR_SPECULAR    = 12;
    const LOC_COLOR_AMBIENT     = 13;
    const LOC_MAP_ALBEDO        = 14;
    const LOC_MAP_DIFFUSE       = 14;
    const LOC_MAP_METALNESS     = 15;
    const LOC_MAP_SPECULAR      = 15;
    const LOC_MAP_NORMAL        = 16;
    const LOC_MAP_ROUGHNESS     = 17;
    const LOC_MAP_OCCLUSION     = 18;
    const LOC_MAP_EMISSION      = 19;
    const LOC_MAP_HEIGHT        = 20;
    const LOC_MAP_CUBEMAP       = 21;
    const LOC_MAP_IRRADIANCE    = 22;
    const LOC_MAP_PREFILTER     = 23;
    const LOC_MAP_BRDF          = 24;

    // Shader uniform data types
    const UNIFORM_FLOAT     = 0;
    const UNIFORM_VEC2      = 1;
    const UNIFORM_VEC3      = 2;
    const UNIFORM_VEC4      = 3;
    const UNIFORM_INT       = 4;
    const UNIFORM_IVEC2     = 5;
    const UNIFORM_IVEC3     = 6;
    const UNIFORM_IVEC4     = 7;
    const UNIFORM_SAMPLER2D = 8;

    // Material map type
    const MAP_ALBEDO     = 0;
    const MAP_DIFFUSE    = 0;
    const MAP_METALNESS  = 1;
    const MAP_SPECULAR   = 1;
    const MAP_NORMAL     = 2;
    const MAP_ROUGHNESS  = 3;
    const MAP_OCCLUSION  = 4;
    const MAP_EMISSION   = 5;
    const MAP_HEIGHT     = 6;
    const MAP_CUBEMAP    = 7;         // NOTE: Uses GL_TEXTURE_CUBE_MAP
    const MAP_IRRADIANCE = 8;         // NOTE: Uses GL_TEXTURE_CUBE_MAP
    const MAP_PREFILTER  = 9;         // NOTE: Uses GL_TEXTURE_CUBE_MAP
    const MAP_BRDF       = 10;

    // Pixel formats
    const UNCOMPRESSED_GRAYSCALE    = 1;      // 8 bit per pixel (no alpha)
    const UNCOMPRESSED_GRAY_ALPHA   = 2;      // 8*2 bpp (2 channels)
    const UNCOMPRESSED_R5G6B5       = 3;      // 16 bpp
    const UNCOMPRESSED_R8G8B8       = 4;      // 24 bpp
    const UNCOMPRESSED_R5G5B5A1     = 5;      // 16 bpp (1 bit alpha)
    const UNCOMPRESSED_R4G4B4A4     = 6;      // 16 bpp (4 bit alpha)
    const UNCOMPRESSED_R8G8B8A8     = 7;      // 32 bpp
    const UNCOMPRESSED_R32          = 8;      // 32 bpp (1 channel - float)
    const UNCOMPRESSED_R32G32B32    = 9;      // 32*3 bpp (3 channels - float)
    const UNCOMPRESSED_R32G32B32A32 = 10;     // 32*4 bpp (4 channels - float)
    const COMPRESSED_DXT1_RGB       = 11;     // 4 bpp (no alpha)
    const COMPRESSED_DXT1_RGBA      = 12;     // 4 bpp (1 bit alpha)
    const COMPRESSED_DXT3_RGBA      = 13;     // 8 bpp
    const COMPRESSED_DXT5_RGBA      = 14;     // 8 bpp
    const COMPRESSED_ETC1_RGB       = 15;     // 4 bpp
    const COMPRESSED_ETC2_RGB       = 16;     // 4 bpp
    const COMPRESSED_ETC2_EAC_RGBA  = 17;     // 8 bpp
    const COMPRESSED_PVRT_RGB       = 18;     // 4 bpp
    const COMPRESSED_PVRT_RGBA      = 19;     // 4 bpp
    const COMPRESSED_ASTC_4x4_RGBA  = 20;     // 8 bpp
    const COMPRESSED_ASTC_8x8_RGBA  = 21;     // 2 bpp

    // Texture parameters: filter mode
    const FILTER_POINT           = 0;     // No filter, just pixel aproximation
    const FILTER_BILINEAR        = 1;     // Linear filtering
    const FILTER_TRILINEAR       = 2;     // Trilinear filtering (linear with mipmaps)
    const FILTER_ANISOTROPIC_4X  = 3;     // Anisotropic filtering 4x
    const FILTER_ANISOTROPIC_8X  = 4;     // Anisotropic filtering 8x
    const FILTER_ANISOTROPIC_16X = 5;     // Anisotropic filtering 16x

    // Cubemap layout type
    const CUBEMAP_AUTO_DETECT         = 0;        // Automatically detect layout type
    const CUBEMAP_LINE_VERTICAL       = 1;          // Layout is defined by a vertical line with faces
    const CUBEMAP_LINE_HORIZONTAL     = 2;        // Layout is defined by an horizontal line with faces
    const CUBEMAP_CROSS_THREE_BY_FOUR = 3;    // Layout is defined by a 3x4 cross with cubemap faces
    const CUBEMAP_CROSS_FOUR_BY_THREE = 4;    // Layout is defined by a 4x3 cross with cubemap faces
    const CUBEMAP_PANORAMA            = 5;                // Layout is defined by a panorama image (equirectangular map)

    // Texture parameters: wrap mode
    const WRAP_REPEAT        = 0;        // Repeats texture in tiled mode
    const WRAP_CLAMP         = 1;             // Clamps texture to edge pixel in tiled mode
    const WRAP_MIRROR_REPEAT = 2;     // Mirrors and repeats the texture in tiled mode
    const WRAP_MIRROR_CLAMP  = 3;      // Mirrors and clamps to border the texture in tiled mode

    // Font type, defines generation method
    const FONT_DEFAULT = 0; // Default font generation, anti-aliased
    const FONT_BITMAP  = 1; // Bitmap font generation, no anti-aliasing
    const FONT_SDF     = 2; // SDF font generation, requires external shader

    // Color blending modes (pre-defined)
    const BLEND_ALPHA      = 0; // Blend textures considering alpha (default)
    const BLEND_ADDITIVE   = 1; // Blend textures adding colors
    const BLEND_MULTIPLIED = 2; // Blend textures multiplying colors

    // Gestures type
    const GESTURE_NONE        = 0;
    const GESTURE_TAP         = 1;
    const GESTURE_DOUBLETAP   = 2;
    const GESTURE_HOLD        = 4;
    const GESTURE_DRAG        = 8;
    const GESTURE_SWIPE_RIGHT = 16;
    const GESTURE_SWIPE_LEFT  = 32;
    const GESTURE_SWIPE_UP    = 64;
    const GESTURE_SWIPE_DOWN  = 128;
    const GESTURE_PINCH_IN    = 256;
    const GESTURE_PINCH_OUT   = 512;

    // Camera system modes
    const CAMERA_CUSTOM       = 0;
    const CAMERA_FREE         = 1;
    const CAMERA_ORBITAL      = 2;
    const CAMERA_FIRST_PERSON = 3;
    const CAMERA_THIRD_PERSON = 4;

    // Camera projection modes
    const CAMERA_PERSPECTIVE  = 0;
    const CAMERA_ORTHOGRAPHIC = 1;

    // Head Mounted Display devices
    const HMD_DEFAULT_DEVICE  = 0;
    const HMD_OCULUS_RIFT_DK2 = 1;
    const HMD_OCULUS_RIFT_CV1 = 2;
    const HMD_OCULUS_GO       = 3;
    const HMD_VALVE_HTC_VIVE  = 4;
    const HMD_SONY_PSVR       = 5;

    // Type of n-patch
    const NPT_9PATCH            = 0; // Npatch defined by 3x3 tiles
    const NPT_3PATCH_VERTICAL   = 1; // Npatch defined by 1x3 tiles
    const NPT_3PATCH_HORIZONTAL = 2; // Npatch defined by 3x1 tiles

    // Some Basic Colors
    public static $LIGHTGRAY;
    public static $GRAY;
    public static $DARKGRAY;
    public static $YELLOW;
    public static $GOLD;
    public static $ORANGE;
    public static $PINK;
    public static $RED;
    public static $MAROON;
    public static $GREEN;
    public static $LIME;
    public static $DARKGREEN;
    public static $SKYBLUE;
    public static $BLUE;
    public static $DARKBLUE;
    public static $PURPLE;
    public static $VIOLET;
    public static $DARKPURPLE;
    public static $BEIGE;
    public static $BROWN;
    public static $DARKBROWN;
    public static $WHITE;
    public static $BLACK;
    public static $BLANK;
    public static $MAGENTA;
    public static $RAYWHITE;

    public static $ffi;

    public static function init()
    {
        $cdef = __DIR__ . '/raylib-php.h';
        static::$ffi = FFI::load($cdef);
        static::initBasicColors();
    }

    private static function initBasicColors()
    {
        static::$LIGHTGRAY = static::Color(200, 200, 200, 255);   // Light Gray
        static::$GRAY =      static::Color(130, 130, 130, 255);   // Gray
        static::$DARKGRAY =  static::Color(80, 80, 80, 255);      // Dark Gray
        static::$YELLOW =    static::Color(253, 249, 0, 255);     // Yellow
        static::$GOLD =      static::Color(255, 203, 0, 255);     // Gold
        static::$ORANGE =    static::Color(255, 161, 0, 255);     // Orange
        static::$PINK =      static::Color(255, 109, 194, 255);   // Pink
        static::$RED =       static::Color(230, 41, 55, 255);     // Red
        static::$MAROON =    static::Color(190, 33, 55, 255);     // Maroon
        static::$GREEN =     static::Color(0, 228, 48, 255);      // Green
        static::$LIME =      static::Color(0, 158, 47, 255);      // Lime
        static::$DARKGREEN = static::Color(0, 117, 44, 255);      // Dark Green
        static::$SKYBLUE =   static::Color(102, 191, 255, 255);   // Sky Blue
        static::$BLUE =      static::Color(0, 121, 241, 255);     // Blue
        static::$DARKBLUE =  static::Color(0, 82, 172, 255);      // Dark Blue
        static::$PURPLE =    static::Color(200, 122, 255, 255);   // Purple
        static::$VIOLET =    static::Color(135, 60, 190, 255);    // Violet
        static::$DARKPURPLE =static::Color(112, 31, 126, 255);    // Dark Purple
        static::$BEIGE =     static::Color(211, 176, 131, 255);   // Beige
        static::$BROWN =     static::Color(127, 106, 79, 255);    // Brown
        static::$DARKBROWN = static::Color(76, 63, 47, 255);      // Dark Brown
        static::$WHITE =     static::Color(255, 255, 255, 255);   // White
        static::$BLACK =     static::Color(0, 0, 0, 255);         // Black
        static::$BLANK =     static::Color(0, 0, 0, 0);           // Blank (Transparent)
        static::$MAGENTA =   static::Color(255, 0, 255, 255);     // Magenta
        static::$RAYWHITE =  static::Color(245, 245, 245, 255);   // My own White (raylib logo)
    }

    public static function Color($r, $g, $b, $a)
    {
        $c = RayLib::new("Color");
        $c->r = $r;
        $c->g = $g;
        $c->b = $b;
        $c->a = $a;
        return $c;
    }

    public static function Vector2($x, $y)
    {
        $v = RayLib::new("Vector2");
        $v->x = $x;
        $v->y = $y;
        return $v;
    }

    public static function Vector3(float $x, float $y, float $z)
    {
        $v = RayLib::new("Vector3");
        $v->x = $x;
        $v->y = $y;
        $v->z = $z;
        return $v;
    }

    public static function Camera3D()
    {
        return RayLib::new("Camera3D");
    }

    public static function Camera()
    {
        return  RayLib::new("Camera3D");
    }


    public static function __callStatic($method, $args)
    {
        $callable = [static::$ffi, $method];
        // TODO: argument unpack segfaults
        // return static::getFFI()->$method(...$args);
        switch (count($args)) {
        case 0:
            return $callable();
        case 1:
            return $callable($args[0]);
        case 2:
            return $callable($args[0], $args[1]);
        case 3:
            return $callable($args[0], $args[1], $args[2]);
        case 4:
            return $callable($args[0], $args[1], $args[2], $args[3]);
        case 5:
            return $callable($args[0], $args[1], $args[2], $args[3], $args[4]);
        case 6:
            return $callable($args[0], $args[1], $args[2], $args[3], $args[4], $args[5]);
        case 7:
            return $callable($args[0], $args[1], $args[2], $args[3], $args[4], $args[5], $args[6]);
        }
    }
}
