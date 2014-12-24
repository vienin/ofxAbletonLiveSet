#include "Model.h"

OFX_ALS_BEGIN_NAMESPACE

float Automation::getValueAt(float time) const {
	if (events.size() < 2) return -1;
	
	map<float, float>::const_iterator start = events.upper_bound(time);
	map<float, float>::const_iterator end = start;
	start--;
	
	if (start == events.begin()) return start->second;
	if (end == events.end()) return start->second;
	
	const float t = time - start->first;
	const float td = end->first - start->first;
	const float vd = end->second - start->second;

	return start->second + vd * (t / td);
}

OFX_ALS_END_NAMESPACE