#include "../Utils/utils.hpp"



namespace transUtils {
    enum class transtype { none, translate, rotate, scale, color };

    class transform {
        float x;
        float y;
        float z;
        float angle;
        transtype type;

    public:
        void setTransform();
        void setTransform(float, float, float, float, transtype);
        float getX();
        float getY();
        float getZ();
        float getAngle();
        transtype getType();
    };

    class transfTime {
        transtype type;
        int time;
        float x;
        float y;
        float z;
        std::vector<utils::point> points;

    public:
        void setTransfTime();
        void setTranslateTime(transtype, int, std::vector<utils::point>);
        void setRotateTime(transtype, int, float, float, float);
        float getX();
        float getY();
        float getZ();
        std::vector<utils::point> getPoints();
        transtype getType();


    };


}