#pragma once
#include "File.h"
class VideoFile :
	public File
{
public:
	VideoFile();
	VideoFile(const File *f);
	VideoFile(string name, string path);
	~VideoFile();

	ofVideoPlayer video;							//Image
	static string filesFolderPath;					//Path to files
	static string thumbnailFolderPath;				//Path to thumbnails
	static string thumbnailIconPath;				//Path to camera icon to add to thumbnail
	static vector <string> availableFormats;			//Required to distinguish images from videos and other files

	double abruptness;
	double motion;
	double shake;
	double fgArea;
	double focus_dif;
	double luminance_std;
	double ranksum;
	double shadow;
	unsigned short predict;
	int interest_1;

	///////////////////Methods////////////////////////
public:

	//void show();					//Call when clicked. Show metadata 
	//void open();					//Call when double-clicked. OPen full screen?
	//virtual void load(string path) override;
	//virtual void draw() override;
	string generateThumbnail() override;
	bool generateXmlFile() override;
	bool getMetadataFromXml()  override;
	bool getMetadataFromCsv(vector<string> csvData) override; // csv parse

	void setThumbnailPath() override;
	bool loadThumbnail() override;
	void draw(ofRectangle space, bool play, ofTrueTypeFont *playerText);
	void draw(int x, int y, bool play);
	void stopVideo();

private:

};
