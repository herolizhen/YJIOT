package com.yjyz.iot.mq.plugin;

import org.apache.activemq.broker.Broker;
import org.apache.activemq.broker.BrokerPlugin;
import org.springframework.jdbc.core.JdbcTemplate;


public class AuthPlugin implements BrokerPlugin {
    JdbcTemplate jdbcTemplate;//◊¢»Î¡Àspring-jdbc
    public AuthPlugin(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate=jdbcTemplate;
    }
    
    @Override
    public Broker installPlugin(Broker broker) throws Exception {
        return new AuthBroker(broker,jdbcTemplate);
    }
}