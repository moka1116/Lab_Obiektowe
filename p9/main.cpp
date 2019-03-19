//
// Created by Kamil Motyka on 05.07.2018.
//


    struct vec3{
        int x;
        int y;
        int z;
    };
    vec3 operator+(vec3 a,vec3 b){
        return{a.x+b.x,a.y+b.y,a.z+b.z};

    }
    vec3 operator+=(vec3 a, vec3 b){
        return{
           a.x += b.x,
           a.y += b.y,
           a.z += b.z
        };
    }
    vec3 operator-(vec3 a, vec3 b) {
        return {
                a.x - b.x,
                a.y - b.y,
                a.z - b.z
        };

    }
    vec3 operator*(vec3 a, int k){
        return{
                a.x*k,
                a.y*k,
                a.z*k
        };
    }



int main(){
}