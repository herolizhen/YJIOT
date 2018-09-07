package com.yjyz.iot.mq.listener.topic;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.TextMessage;

import org.springframework.stereotype.Component;

@Component("topicReceiverC2D")
public class TopicReceiverC2D implements MessageListener {
	@Override
	public void onMessage(Message message) {
		try {
			System.out.println("TopicReceiverC2D接收到消息:" + ((TextMessage) message).getText());
		} catch (JMSException e) {
			e.printStackTrace();
		}
	}

}