package com.yjyz.iot.notice.dao;

import java.util.List;

import com.yjyz.iot.notice.entity.NoticePush;
import com.yjyz.iot.notice.entity.NoticePushKey;

public interface NoticePushMapper {
	int deleteByPrimaryKey(NoticePushKey key);

	int insert(NoticePush record);

	int insertSelective(NoticePush record);

	NoticePush selectByPrimaryKey(NoticePushKey key);

	int updateByPrimaryKeySelective(NoticePush record);

	int updateByPrimaryKey(NoticePush record);

	List<NoticePush> selectByProductId(String productId);
}