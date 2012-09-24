#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Square.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoySocApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings ) { settings->enableMultiTouch( false ); }
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void keyDown(KeyEvent event);
	bool help;
	gl::TextureFontRef	mTextureFont;
	Font mFont;
};

void RoySocApp::setup()
{
	help = true;
	#if defined( CINDER_COCOA_TOUCH )
	mFont = Font( "Cochin-Italic", 24 );
#elif defined( CINDER_COCOA )
	mFont = Font( "BigCaslon-Medium", 24 );
#else
	mFont = Font( "Times New Roman", 24 );
#endif
	mTextureFont = gl::TextureFont::create( mFont );
}

void RoySocApp::mouseDown( MouseEvent event )
{
}

void RoySocApp::keyDown(KeyEvent event)
{
if (event.getChar() == '?'){
	gl::clear( Color( 0, 0, 0 ) ); 
		help = !(help);
	}
}

void RoySocApp::update()
{
}

void RoySocApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	gl::setMatricesWindow( getWindowSize() );
	gl::enableAlphaBlending();
	gl::clear( Color( 0, 0, 0 ) );
	
	if (help==true){std::string str( "Press '?' to toggle instructions" );
	Rectf boundsRect( 40, mTextureFont->getAscent() + 40, getWindowWidth() - 40, getWindowHeight() - 40 );

	gl::color( ColorA( 1, 0.5f, 0.25f, 1.0f ) );

	mTextureFont->drawStringWrapped( str, boundsRect );
	}
}

CINDER_APP_BASIC( RoySocApp, RendererGl(0) )
