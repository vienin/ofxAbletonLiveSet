#pragma once

#include "Constants.h"
#include "Time.h"
#include "Tempo.h"

OFX_ALS_BEGIN_NAMESPACE

typedef float Time;

struct Note {
	Time time;
	Time duration;
	float velocity;
	int key;
};

struct Automation {
	int id;
	float getValueAt(float time) const;
	map<float, float> events;
};

struct MidiClip {
	Time time;
	Time endtime;
	Time duration;
	
	string name;
	string annotation;
	int color;
	
	vector<Note> notes;
	vector<Automation> envelopes;
};

struct Track {
	string name;
	int color;
};

struct MidiTrack : public Track {
	vector<MidiClip> clips;
};

struct Locator {
	Time time;
	string name;
	string annotation;
};

struct LiveSet {
	Tempo tempo;
	vector<Locator> locators;
	vector<MidiTrack> miditracks;
};

OFX_ALS_END_NAMESPACE
