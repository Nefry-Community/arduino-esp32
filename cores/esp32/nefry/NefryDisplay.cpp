#include "NefryDisplay.h"
#include "NefryBTimg.h"
#include <string>

SSD1306  _nefrySsdDisplay(0x3c, SDA2, SCL2);
String _nefryPrintDisplay1 = "", _nefryPrintDisplay2 = "", _nefryPrintDisplay3 = "";
String _dialogTitle = "Nefry PrintDialog";
/* 初期化 */
bool Nefry_Display::begin()
{
	// Initialising the UI will init the display too.
	_nefrySsdDisplay.init();
	_nefrySsdDisplay.flipScreenVertically();
	_nefrySsdDisplay.setContrast(120);

	/* BoardIDで表示する内容をできるようにする */
	_nefrySsdDisplay.drawXbm(0, 0, nefrybt_img_width, nefrybt_img_height, nefrybt_img_bits);
	_nefrySsdDisplay.display();
	return true;
}

void Nefry_Display::setTitle(String title) {
	_dialogTitle = title;
}

void setPrintDialogDisplay() {
	NefryDisplay.setFont(Arimo_12);
	NefryDisplay.drawString(15, 0, _dialogTitle);
	NefryDisplay.drawStringWithHScroll(0, 20, _nefryPrintDisplay1,10);
	NefryDisplay.drawStringWithHScroll(0, 35, _nefryPrintDisplay2, 10);
	NefryDisplay.drawStringWithHScroll(0, 50, _nefryPrintDisplay3, 10);
}

/* 表示 */
bool Nefry_Display::print(String s)
{
	s += "  ";
	if (_nefryPrintDisplayValue < 3) {
		switch (_nefryPrintDisplayValue)
		{
		case 0:
			_nefryPrintDisplay1 = s;
			break;
		case 1:
			_nefryPrintDisplay2 = s;
			break;
		case 2:
			_nefryPrintDisplay3 = s;
			break;
		}
		_nefryPrintDisplayValue++;
	}
	else {
		_nefryPrintDisplay1 = _nefryPrintDisplay2;
		_nefryPrintDisplay2 = _nefryPrintDisplay3;
		_nefryPrintDisplay3 = s;
	}
	setAutoScrollFlg(true);
	autoScrollFunc(setPrintDialogDisplay);
	return true;
}
void Nefry_Display::end()
{
	_nefrySsdDisplay.end();
}

void Nefry_Display::setColor(OLEDDISPLAY_COLOR color)
{
	_nefrySsdDisplay.setColor(color);
}

void Nefry_Display::drawString(int16_t x, int16_t y, String text, int16_t maxLineWidth)
{
	/* スクロール機能未実装 */
	if (maxLineWidth == 0)maxLineWidth = 127;
	_nefrySsdDisplay.drawStringMaxWidth(x, y, maxLineWidth, text);
}

void Nefry_Display::drawStringWithHScroll(int16_t x, int16_t y, String text, int16_t scrollSpeed, int16_t scrollpointer)
{
	int16_t maxLineWidth = 127 - x;
	int16_t textWidth = getStringWidth(text);
	String tempText = text;
	if (scrollpointer == -1) {
		if (_scrollMode == true) {
			if (textWidth > maxLineWidth) {
				long strIndex = _scrollTextCount / scrollSpeed;
				int textLength = text.length();
				long scrollNum = strIndex % textLength;
				String h_text = text.substring(0, scrollNum);
				String l_text = text.substring(scrollNum);
				l_text.concat(h_text);
				tempText = l_text;
			}
		}
	}
	else {
		if (textWidth > maxLineWidth) {
			long strIndex = scrollpointer / scrollSpeed;
			int textLength = text.length();
			long scrollNum = strIndex % textLength;
			String h_text = text.substring(0, scrollNum);
			String l_text = text.substring(scrollNum);
			l_text.concat(h_text);
			tempText = l_text;
		}
	}
	_nefrySsdDisplay.drawString(x, y, tempText);
}

uint16_t Nefry_Display::getStringWidth(const char * text, uint16_t length)
{
	return _nefrySsdDisplay.getStringWidth(text,length);
}
uint16_t Nefry_Display::getStringWidth(String text)
{
	return _nefrySsdDisplay.getStringWidth(text);
}
Nefry_Display NefryDisplay;


void Nefry_Display::setFont(const char * fontData)
{
	_nefrySsdDisplay.setFont(fontData);
}

void Nefry_Display::setPixel(int16_t x, int16_t y)
{
	_nefrySsdDisplay.setPixel(x, y);
}

void Nefry_Display::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
	_nefrySsdDisplay.drawLine(x0, y0, x1, y1);
}

void Nefry_Display::drawRect(int16_t x, int16_t y, int16_t width, int16_t height)
{
	_nefrySsdDisplay.drawRect(x, y, width, height);
}

void Nefry_Display::fillRect(int16_t x, int16_t y, int16_t width, int16_t height)
{
	_nefrySsdDisplay.fillRect(x, y, width, height);
}

void Nefry_Display::drawCircle(int16_t x, int16_t y, int16_t radius)
{
	_nefrySsdDisplay.drawCircle(x, y, radius);
}

void Nefry_Display::fillCircle(int16_t x, int16_t y, int16_t radius)
{
	_nefrySsdDisplay.fillCircle(x, y, radius);
}

void Nefry_Display::drawHorizontalLine(int16_t x, int16_t y, int16_t length)
{
	_nefrySsdDisplay.drawHorizontalLine(x, y, length);
}

void Nefry_Display::drawVerticalLine(int16_t x, int16_t y, int16_t length)
{
	_nefrySsdDisplay.drawVerticalLine(x, y, length);
}

void Nefry_Display::drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress)
{
	_nefrySsdDisplay.drawProgressBar(x, y, width, height, progress);
}

void Nefry_Display::drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const char * xbm)
{
	_nefrySsdDisplay.drawXbm(x, y, width, height, xbm);
}

void Nefry_Display::clear(void)
{
	_nefrySsdDisplay.clear();
}

void Nefry_Display::display(void)
{
	_nefrySsdDisplay.display();
}

void Nefry_Display::invertDisplay(void)
{
	_nefrySsdDisplay.invertDisplay();
}

void Nefry_Display::normalDisplay(void)
{
	_nefrySsdDisplay.normalDisplay();
}

void Nefry_Display::setContrast(char contrast)
{
	_nefrySsdDisplay.setContrast(contrast);
}

void Nefry_Display::flipScreenVertically()
{
	_nefrySsdDisplay.flipScreenVertically();
}

void Nefry_Display::setAutoScrollFlg(bool scroll)
{
	_scrollMode = scroll;
}

void Nefry_Display::autoScrollFunc(GeneralFunction func)
{
	_func = func;
}

void Nefry_Display::autoScrollTask()
{
	if (_func != NULL) {
		clear();
		_scrollTextCount++;
		_func();
		display();
	}
}
