class Light
{
private:
    int m_on;
    int m_bri;
    int m_hue;
    int m_sat;

public:
    int getOn();
    void setOn(int val);
    int getBri();
    void setBri(int val);
    int getHue();
    void setHue(int val);
    int getSat();
    void setSat(int val);

};