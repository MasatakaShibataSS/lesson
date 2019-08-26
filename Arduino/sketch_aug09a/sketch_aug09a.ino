#define ARYSIZE 10
String dst_str[ARYSIZE] = {"\0"}; // 分割された文字列を格納する配列 
 
int split(String *dst, size_t arraySize, String src, char delimiter){
    int index = 0;
    int srclength = src.length();
    dst[index] = "";
    for (int i = 0; i < srclength; i++) {
        char tmp = src.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
            dst[index] = "";
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
 
void setup() {
  // 文字列
  String src_str = "hoge,foo,bar";
 
  // 分割数 = 分割処理(格納先配列, 配列要素数, 文字列, 区切り文字)
  int index = split(dst_str, ARYSIZE, src_str, ',');
 
  // 結果表示
  Serial.begin(9600);
  for(int i = 0; i < index; i++){
    Serial.println(dst_str[i]);
  }
}
 
void loop() {
 
}
