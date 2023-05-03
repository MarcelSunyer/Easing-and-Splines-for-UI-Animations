#include "External/Tweeny/tweeny.h"

//TODO 1: Define all the types of animations easing library has
enum Easings
{
    DEF,
  

};



class Tween
{
public:
    Tween();
    Tween(float multiplier, float smoothness, bool suppressCallbacks);
    ~Tween();

    //Set the initial conditions of the tween (start, end, time(ms) and type of easing)
    void Set(int start, int finish, int time, Easings easingMode)
    {
        //Aplly all the characteristics of the animation
        tween = tweeny::from(start).to(finish * smoothness).during(time);
        nextPos = finish;
        totalLength += nextPos;

        //TODO 2: Apply the animations to the definition
        switch (easingMode)
        {
       
        default:
            tween.via(tweeny::easing::def);
            break;
        }
    }

    void Set()
    {
        totalTweenings = 1;
        currentTweening = 1;
        tween = tweeny::from(0).to(0 * smoothness).during(1).via(tweeny::easing::def);
        nextPos = 0;
        totalLength += nextPos;
    }

    //Adda new animation (time in ms)
    void AddTween(int duration, int time, Easings easingMode)
    {
        float currentPoint = tween.progress() * tween.duration();
            tween.to((duration) * smoothness).during(time);

        tween.seek((int32_t)currentPoint, false);
        
        //TODO 2: Apply the animations to the definition
        switch (easingMode)
        {
     
        default:
            tween.via(tweeny::easing::def);
            break;
        }
    }
    //Waits a certain amount of time(ms) before entering the next tween
    void Wait(int time)
    {
        tween.to(nextPos).during(time);
    }
    //Updates the tween in whole positions. Returns the current point of the tween
	int Step(int amount, bool suppressCallbacks)
	{
		return tween.step(amount, suppressCallbacks);
        this->suppressCallbacks = suppressCallbacks;
	}
    //Updates the tween in percentages. Returns the current point of the tween
    int Step(float amount, bool suppressCallbacks)
    {
        return tween.step(amount, suppressCallbacks);
    }
    // Returns the current point of the tween without updating it.
	float GetPoint()
	{

		return (float)tween.peek() * multiplier / smoothness;
	}
    void SetEasing(Easings easingMode)
    {
        //TODO 2: Apply the animations to the definition
        switch (easingMode)
        {
        
        default:
            tween.via(tweeny::easing::def);
            break;
        }
    }

    //Go to a certain point of the tween while interpolating
    int GoTo(int point,bool suppressCallbacks)
    {
        return tween.seek(point, suppressCallbacks);
        
    }

    //Go to a certain percentage of the tween with interpolation
    int GoTo(float point, bool suppressCallbacks)
    {
        return tween.seek(point, suppressCallbacks);
    }

    //Go to a certain point of the tween while NOT interpolating
    int JumpTo(int tweenPos, bool suppressCallbacks)
    {
        return tween.jump(tweenPos, suppressCallbacks);
    }

    void Foward()
    {
        tween.forward();
    }

    void Backward()
    {
        tween.backward();
    }

    float Progress()
    {
        return tween.progress();
    }

    uint32_t TotalDuration()
    {
        
        return tween.duration();
    }
    
    int Direction()
    {
        return tween.direction();
    }
    

    tweeny::tween<int> Main() const
    {
        return tween;
    }

public:
    float multiplier;
    float smoothness;
    bool suppressCallbacks;
private:
	tweeny::tween<int> tween;
    int nextPos;
    int totalLength;
    int accumDuration;
    int totalTweenings;
    int currentTweening;
};

