#include <iostream>

int StringCount(const char* _String)
{
    int Count = 0;

    while (0 != _String[Count])
    {
        ++Count;
    }

    return Count;
}

// 庚切伸戚 旭精走?
bool StringCompair(const char* _Text0, const char* _Text1)
{
    // 胡煽 庚切伸税 掩戚亜 旭精走採斗 端滴廃陥
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    // 庚切伸税 掩戚亜 陥牽陥檎 辞稽 陥献 庚切伸 昔 依戚陥. 
    if (First != Second)
    {
        return false;
    }
    
    // 庚切伸税 掩戚幻鏑 鋼差, 確庚切研 薦須廃 掩戚亜 10戚虞檎
    // 0 ~ 9 猿走 恥 10腰鋼差廃陥. 
    for (int i = 0; i < First; ++i)
    {
        // 馬蟹梢 搾嘘馬食 辞稽 陥牽陥檎 陥献 庚切伸 昔 依戚陥.
        if (_Text0[i] != _Text1[i])
        {
            return false;
        }
    }
  
    // for 庚 鎧採拭 if 庚拭 杏軒走 省壱 魁猿走 庚切伸掩戚 魁猿走 溌昔 板 
    // 焼掘 坪球稽 鎧形尽陥檎 辞稽 旭精 庚切伸戚虞澗 税耕戚陥. 
    return true;
}

// 庚切伸 杯帖奄 
void StringMerge(char* _Result, const char* _Text0, const char* _Text1)
{
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    int ConnectIdx = 0;

    for(int i = 0; i < First; ++i)
    {
        // 確庚切亜 蟹臣凶 猿走 庚切伸聖 差紫廃陥. 
        if (0 != _Text0[i])
        {
            _Result[i] = _Text0[i];
        }   
        ++ConnectIdx;
    }

    // 差紫亜 刃戟吉 板 陥製 昔畿什葵聖 条嬢鎌奄 凶庚拭
    // 陥製昔畿什採斗 砧腰属稽 級嬢紳 昔切税 庚切伸税 確庚切亜 蟹臣凶 猿走 
    // 戚嬢辞 企脊背層陥.
    
    for (int i = 0; i < Second; ++i)
    {
        if (0 != _Text1[i])
        {
            _Result[ConnectIdx] = _Text1[i];
            ++ConnectIdx;
        }
    }

    // 乞窮 拙穣戚 刃戟鞠醸陥檎 衣引葵拭 原走厳 庚切伸拭 0聖 企脊背辞 魁聖 硝呪 赤亀系 坦軒廃陥.
    _Result[ConnectIdx] = 0;
}


void StringChange(char* _Text, const char* _Old, const char* _New)
{
    // 確庚切研 捌 庚切伸 掩戚穴 姥廃陥.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // 郊蚊匝 庚切伸税 掩戚研 姥廃陥.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // 歯 庚切伸税 掩戚研 姥廃陥.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }
    
    // 護鯵税 庚切研 郊荷嬢醤 拝走 鯵呪研 姥廃陥. 
    int ChangeTextCount = 0;
    
    // 郊蚊匝 獣拙 昔畿什研 姥廃陥.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // 鋼差宜檎辞 疑析廃 庚切研 達澗陥.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // 達紹陥檎 及楕 庚切伸亀 溌昔廃陥. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[i + j] == _Old[j])
                {
                    ++ChangeTextCount;
                }
            }

            // 郊蚊匝 庚切人 疑析廃走 溌昔戚 菊奄 凶庚拭 for庚 曽戟
            break;
        }
    }

    // 痕井拝 庚切研 隔嬢層陥. 
    // 戚 凶 痕井拝 努什闘鯵呪左陥 歯稽錘 努什闘税 鯵呪亜 拙陥檎 森須坦軒背醤馬澗汽.. 益惟 ex昔牛
    // 努什闘鯵呪亜 護鯵 希 拙精走 域至背辞 郊蚊爽壱 益 戚板 昔畿什澗 廃牒梢 強移 
    int Value = ChangeTextCount - NewTextCount;

    // 辞稽 努什闘税 鯵呪亜 旭陥檎 戚係惟 坦軒
    if (Value == 0)
    {
       for (int i = 0; i < ChangeTextCount; ++i)
       {
           _Text[ChangeIdx + i] = _New[i];
       }
   
    }
    
    // 辞稽 努什闘 鯵呪亜 陥牽陥檎 拙穣戚 刃戟 鞠壱 蟹檎 及楕 昔畿什研 蒋生稽 辰趨層陥. 
    else
    {
        for (int i = 0; i < ChangeTextCount; ++i)
        {
            _Text[ChangeIdx + i] = _New[i];
        }

        int MoveIdx = ChangeIdx + ChangeTextCount;
        for (int i = 0; i < INT_MAX; ++i)
        {
            _Text[MoveIdx + i] = _Text[MoveIdx + i + 1];
            
            // 庚切伸税 魁聖 幻蟹檎 for 庚 曽戟 
            if (_Text[MoveIdx + i] == 0)
                break;
        }
    }
    
}

void StringChangeEx(char* _Text, const char* _Old, const char* _New)
{
    // 確庚切研 捌 庚切伸 掩戚穴 姥廃陥.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // 郊蚊匝 庚切伸税 掩戚研 姥廃陥.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // 歯 庚切伸税 掩戚研 姥廃陥.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }

    // 郊蚊醤拝 庚切 鯵呪 
    int ChangeTextCount = 0;

    // 郊蚊匝 獣拙 昔畿什研 姥廃陥.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // 鋼差宜檎辞 疑析廃 庚切研 達澗陥.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // 達紹陥檎 及楕 庚切伸亀 溌昔廃陥. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[ChangeIdx + j] == _Old[j])
                {
                    // 痕井背醤拝 庚切鯵呪 蓄亜
                    ++ChangeTextCount;
                }
            }

            // 郊蚊匝 庚切人 疑析廃走 溌昔戚 菊奄 凶庚拭 for庚 曽戟
            break;
        }
    }
    
    // 庚切伸 掩戚端滴 
    bool Check = OldTextCount >= NewTextCount;

    // true 虞檎 奄糎 努什闘亜 希 掩暗蟹 旭製
    if (Check)
    {
        // 歯 庚切伸税 昔畿什 葵 
        int NewIdx = 0;

        // ConnectIdx = 背雁 昔畿什採斗 庚切研 戚嬢細食層陥. 
        // 戚嬢細食匝 昔畿什 = 郊蚊匝 昔畿什腰硲 + 痕井背醤拝 庚切鯵呪 
        int ConnectIdx = ChangeIdx + ChangeTextCount;

        // 庚切伸税 魁聖 幻劾凶 猿走 叔楳
        while (0 != _New[NewIdx])
        {
            // 企脊
            _Text[ChangeIdx] = _New[NewIdx];

            // 差紫吃 凶原陥 Index + 1
            ++ChangeIdx;
            ++NewIdx;
        }

        // 庚切伸税 魁聖 幻劾凶 猿走 叔楳
        while (0 != _Text[ConnectIdx])
        {
            // 企脊
            _Text[ChangeIdx] = _Text[ConnectIdx];

            // 企脊 吃 凶原陥 Index + 1
            ++ChangeIdx;
            ++ConnectIdx;
        }

        // 拙穣戚 乞砧 魁概陥檎 庚切伸戚 乞砧 脊径吉 依戚壱 
        // ChangeIdx 澗 確庚切亜 級嬢哀 切軒析 依戚陥. 0企脊.
        _Text[ChangeIdx] = 0;
    }

    // 歯稽錘 努什闘 庚切伸税 掩戚亜 奄糎 庚切伸左陥 掩陥檎 焼掘 号縦生稽 遭楳
    else
    {
        // 隔嬢匝 庚切壕伸税 Index 葵
        int Count = 0;
        // 戚嬢辞 細食操醤拝 庚切税 獣拙昔畿什 
        int ConnectIdx = ChangeIdx + ChangeTextCount;

        // 痕井吃 庚切伸税 及楕 庚切伸聖 魚稽 煽舌背黍陥. 
        // ConnectIdx 採斗 庚切伸税 魁猿走 煽舌

        int TextIdx = 0;
        char Text[100] = {};

        // 戚嬢細析 庚切伸聖 魚稽 煽舌背砧壱
        // 痕井戚 刃戟 鞠醸奄 凶庚拭 魁貝走繊採斗 陥獣 戚嬢層陥
        while (0 != _Text[ConnectIdx])
        {
            Text[TextIdx] = _Text[ConnectIdx];
            ++TextIdx;
            ++ConnectIdx;
        }

        // 庚切伸 企脊
        while (0 != _New[Count])
        {
            _Text[ChangeIdx] = _New[Count];

            ++ChangeIdx;
            ++Count;
        }

        // 煽舌背砧醸揮 庚切伸聖 戚嬢細食層陥. 
        int TextCount = 0;
        while (0 != Text[TextCount])
        {
            _Text[ChangeIdx] = Text[TextCount];
            ++ChangeIdx;
            ++TextCount;
        }

        // 坪球亜 食奄猿走 鎧形尽陥檎 乞窮 拙穣戚 魁概奄 凶庚拭
        // 原走厳生稽 痕井吉 昔畿什 陥製腰属拭 0聖 隔嬢層陥. 
        // 薄仙 益陥製 腰属 昔畿什 葵生稽 竺舛鞠嬢 赤奄 凶庚拭 0 企脊 
        _Text[ChangeIdx] = 0;
    }
}
int main()
{
    // StrngChange
    {
        char Arr[100] = "aaa bbb ccc";

        StringChange(Arr, "bbb", "ddd");
        printf("StringChange : %s\n", Arr);
    }
    // --------------------------------------------------- // 

    // StringChangeEx 
    {
        char Arr[100] = "aaa bbb check";
       
        StringChangeEx(Arr, "bbb", "Teけいしかいし");
        printf("%s", "============================\n");
        printf("StringChangeEx : %s\n", Arr);
    }

 
    // StringCompair
	char Arr[20] = "設鞠蟹?";
	{
        // true
		bool result = StringCompair(Arr, "設鞠蟹?");

        int a = 0;
	}

	{
        // false
		bool result = StringCompair(Arr, "設照鞠蟹???");

		int a = 0;
	}


    // StringMerge
    {
        char Arr[100] = "";
        printf("%s", "============================\n");
        StringMerge(Arr, "test", "Game Game testest");
        //Arr = "test Game"

        printf("StringMerge : %s\n\n\n\n", Arr);
    }




}
