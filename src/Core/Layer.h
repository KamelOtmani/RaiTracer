#pragma once

class Layer
{
public:
	Layer() {}
	~Layer() {}

	virtual void OnAttach()		= 0;

	virtual void OnStartFrame() = 0;
	virtual void OnUpdate()		= 0;
	virtual void OnEndFrame()	= 0;

	virtual void OnDettach()	= 0;

private:

};