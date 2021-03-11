#ifndef __MUSICPLAYER__
#define __MUSICPLAYER__


struct musicplayher
{
  
   State Current;


};


struct State
{
       Volume track;
   Speed Playback;
    /* data */
};



struct musicFile
{
    /* data */
};


void ChangeVolume(); // This funciton changes volume
void Queue;
void Dequeue;
void play;
Void SwitchLoopState;
void seek;
void changeTrack;
void stop;

void SongSearch();

void InputStyle;//bluetooth, usb etc



#endif