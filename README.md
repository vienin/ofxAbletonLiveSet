ofxAbletonLiveSet
=================

Ableton Live Set (.als) Project File parser.  
Loads an .als (or .xml) Ableton Live set into OpenFrameworks variables.  
Useful for syncronising visuals with audio composed with Live.

_Note: This plugin doesn't let you control Ableton via OSC. (use [ofxAbleton](https://github.com/tassock/ofxAbleton) for that)_

------
##Usage
Please refer to the __project examples__ for detailed information.  
######Parse ALS file
	ofxAbletonLiveSet::LiveSet LS;
	ofxAbletonLiveSet::Parser parser(LS);
	// LS now contains various live set data
######Events:
	ofxAbletonLiveSet::EventHandler eventHandler;
	ofAddListener(ofx::AbletonLiveSet::EventHandler::noteEvent, this, &ofApp::noteEventListener);
	eventHandler.enableNoteEvents(LS);
	
	void ofApp::noteEventListener(ofx::AbletonLiveSet::LSNoteEvent & noteEvent){
		cout << "Note Event: " << noteEvent.note.key << " @ " << noteEvent.note.time << endl;
	}


_________
##Features  
######Data Extraction

- __MasterTrack__ (Name, Bpm, Time Signature)
- __MidiTrack__ (Name, MidiClips, Envelopes, MidiNotes, etc.)
- __AudioTrack__ (Soon...)
- __Locations__ (Sort of Ableton Markers)

######Event Nofication  
- Notify of metronom events.
- Notify of note events.

---------
##Not yet implemented
- Some plugins carry floatEvents or boolEvents or enumEvents  
- Some tracks can have WarpMarkers
- Tempo Automation _(when the pbm changes)_ not yet supported

Do you have other ideas ?  
Feel free to contribute! :D


