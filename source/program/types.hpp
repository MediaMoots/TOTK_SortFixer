#pragma once

namespace sead
{
    struct SafeString
    {
        char *string;
        size_t bufCapacity;
        size_t length;
    };

    struct BufferedSafeStringBaseChar{
        SafeString mString;
        int mBufferSize;
    };
}

namespace pp::TypedParam
{
    struct ParentResolver {
        void* mpDocument;     
        void* mpParentHandle;   
        uint32_t mParentId;     
        uint32_t unknown3;     
    };

    struct TypedParam {
        void* mVtable;      
        char* mpParentPath;    
        ParentResolver mParentResolver;  
        void* mpHandle;    
    };

    struct PropBuffer {
        void* mVtable;    
        void* mpInfo;        
        PropBuffer* mpParent; 
        void** mpBuffer;    
        int mMax;         
        int mCount;       
    };

    struct PouchSortTable {
        TypedParam mBase;                 
        PropBuffer mArmorCategory;         
        PropBuffer mArmorDyeColor;          
        PropBuffer mArmorSeries;            
        PropBuffer mBowEffect;             
        PropBuffer mFoodEffect;
        sead::SafeString mMaterialBowAttachmentTag;
        
        PropBuffer mMaterialCategory;       
        PropBuffer mShieldEffect;           
        PropBuffer mWeaponCategory;         
        PropBuffer mWeaponEffect;          
    
        bool mWeaponCategoryIsPresent;    
        bool mWeaponEffectIsPresent;       
        bool mBowEffectIsPresent;           
        bool mShieldEffectIsPresent;     
        bool mArmorCategoryIsPresent;      
        bool mArmorDyeColorIsPresent;       
        bool mArmorSeriesIsPresent;         
        bool mMaterialCategoryIsPresent;    
        bool mMaterialBowAttachmentTagIsPresent; 
        bool mFoodEffectIsPresent;   
    };
}
