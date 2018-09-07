package com.yjyz.iot.notice.dao;

import com.yjyz.iot.notice.entity.NoticeRule;

public interface NoticeRuleMapper {
    int deleteByPrimaryKey(String productId);

    int insert(NoticeRule record);

    int insertSelective(NoticeRule record);

    NoticeRule selectByPrimaryKey(String productId);

    int updateByPrimaryKeySelective(NoticeRule record);

    int updateByPrimaryKey(NoticeRule record);
}