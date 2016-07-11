{
    float3 pos : POSITION;
};

struct PIXEL_IN
{
    float4 pos : SV_POSITION;
};

PIXEL_IN main(VERTEX_IN inp)
{
    PIXEL_IN ret;
    return ret;
}
