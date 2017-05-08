#pragma once


/**************/
/** GEOMETRY **/
/**************/

/** Vectors definition **/
typedef struct _vector2D
{
	float x;
	float y;
} Vector2D;

typedef struct _vector3D
{
	float x;
	float y;
	float z;
} Vector3D;

/** Polygon coordinates for easy manipulation **/
typedef struct _polygon
{
	int BBox;
	Vector2D * points;
	int nbrPoints;
} Polygon;

/** Circle coordinates for easy manipulation **/
typedef struct _circle
{
	int BBox;
	float radius;
	Vector2D position;
} Circle;

/** Collision is used to store data about a collision event **/
typedef struct _collisionData
{
	enum CollisionSide side;
	Vector2D point;

	float delta;
} Collision;





/** The watched keys **/
typedef struct _keyPressed
{
    /*Nav & player 1*/
    bool up;
    bool down;
    bool left;
    bool right;
    bool enter;
    bool esc;

    /*player 2*/
    bool a;
    bool z;
    bool e;

    /*player 3*/
    bool b;
    bool n;
    bool v;
} KeyPressed;



/*******************/
/** TEXT ELEMENTS **/
/*******************/

/*Store a character texture and positioning*/
typedef struct _character
{
	GLuint texture;
	Vector2D size;
	Vector2D bearing;
	GLuint advance;
} Character;

/*Store a font with all it's characters*/
typedef struct _font
{
	char name[100];	
	
	int size;

	Character chars[128];
} Font;







/********************/
/** PRINT ELEMENTS **/
/********************/

/*A player plateforme*/
typedef struct _platforme
{
	int BBox;

	float x;
	float y;
	int size;
	int dirFactor;

	float speed;

	GLuint texture;

	bool sticky;
	int stickyEnd;

	enum bonusType bonus;
	int bonusEnd;

	int elementID;
} Plateforme;

/*A brick*/
typedef struct _brick
{
	int BBox;

	Vector2D topLeft;
	Vector2D topRight;
	Vector2D bottomRight;
	Vector2D bottomLeft;

	enum brickType type;

	int strength;

	GLuint texture;
	GLuint texture1;
	GLuint texture2;
} Brick;

typedef struct _wall
{
	int BBox;

	Vector2D topLeft;
	Vector2D topRight;
	Vector2D bottomRight;
	Vector2D bottomLeft;

	GLuint texture;
} Wall;

/*A ball*/
typedef struct _ball
{
	int BBox;

	float x;
	float y;
	float size;

	int playerID;

	bool glued;
	Plateforme * gluedPlat;
	float glueOffsetX;
	int gluedAt;

	GLuint texture;

	Vector2D direction;
	float speed;
	
	enum bonusType bonus;
	int bonusEnd;

	int elementID;
} Ball;

/*A bonus*/
typedef struct _bonus
{
	int BBox;
	
	float x;
	float y;
	
	enum bonusType type;

	GLuint texture;

} Bonus;

/*A text*/
typedef struct _text
{
	int BBox;

	int x;
	int y;

	char text[256];

	enum textAlign align;
	Vector3D color;

	Font * font;
} Text;

/*A button*/
typedef struct _button Button;

struct _button {
	int x;
	int y;
	int width;
	int height;

	GLuint idleTexture;
	GLuint selectedTexture;

	enum elState state;
	char callback;

	bool functionBtn;
	void (*functionCallback)(void *);
	void * callbackArgument;

	bool isNumberBox;
	Text * text;

	Button * leftBtn;
	Button * topBtn;
	Button * rightBtn;
	Button * bottomBtn;
};

/*A picture*/
typedef struct _picture
{
	int BBox;

	int x;
	int y;
	int width;
	int height;

	GLuint texture;
} Picture;

/*A numberbox*/
typedef struct _numberBox
{
	int value;
	int min;
	int max;

	Button * btn;
	Text * display;

} NumberBox;

/*Holder for an element in the printArray*/
typedef struct _printElement
{
	union 
	{
		Plateforme * plateforme;
		Brick * brick;
		Wall * wall;
		Ball * ball;
		Bonus * bonus;
		Button * btn;
		Picture * pict;
		NumberBox * nBox;
		Text * txt;
	} element;
	enum elType type;
	bool display;

} PrintElement;

/*A player*/
typedef struct _player
{
	enum PlayerType type;

	int life;
	int score; /* ~ */

	int controls;
	bool reversed;

	Plateforme * plateforme;
	Text * lifeText;
} Player;
