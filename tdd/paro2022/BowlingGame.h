#pragma once

class BowlingGame {
    int points = 0, lastRoll = -1, lastLastRoll = -1, tripleStrike=0, noRoll=0;
public:
    void roll(int pins) {
        if(noRoll==20){
            if(lastRoll + lastLastRoll == 10)
                points+=pins;
        } else if (lastRoll + lastLastRoll == 10||lastRoll == 10 || lastLastRoll == 10) {
            if (lastRoll == 10 && lastLastRoll == 10&&pins==10)
                points += 10;
            points += pins * 2;
        }
        else
            points += pins;
        lastLastRoll = lastRoll;
        lastRoll = pins;
        noRoll++;
        if (pins==10)
            noRoll++;
    }

    int getScore() const {
        return points;
    }

private:
};

