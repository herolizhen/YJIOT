package com.yjyz.iot.mq.plugin;

import java.security.Principal;
import java.util.HashSet;
import java.util.Set;

import java.security.cert.X509Certificate;

import org.apache.activemq.broker.Broker;
import org.apache.activemq.broker.ConnectionContext;
import org.apache.activemq.command.ConnectionInfo;
import org.apache.activemq.jaas.GroupPrincipal;
import org.apache.activemq.security.AbstractAuthenticationBroker;
import org.apache.activemq.security.SecurityContext;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import com.yjyz.iot.device.entity.DeviceInfo;

/**
 * 
 * @calss :AuthBroker
 * @TODO :
 * @author:HeroLizhen
 * @date :2017年11月24日下午4:57:08
 */
public class AuthBroker extends AbstractAuthenticationBroker {

	private static Log log = LogFactory.getLog(AuthBroker.class);

	private JdbcTemplate jdbcTemplate;

	public AuthBroker(Broker next, JdbcTemplate jdbcTemplate) {
		super(next);
		this.jdbcTemplate = jdbcTemplate;
	}

	@Override
	public void addConnection(ConnectionContext context, ConnectionInfo info) throws Exception {
		log.error("YJIOT Connection IP:" + info.getClientIp() + " clientid:" + info.getClientId());
		System.out.println("YJIOT Add Connection IP:" + info.getClientIp() + " clientid:" + info.getClientId());
		SecurityContext securityContext = context.getSecurityContext();
		if (securityContext == null) {
			securityContext = authenticate(info.getUserName(), info.getPassword(), null);
			context.setSecurityContext(securityContext);
			securityContexts.add(securityContext);
		}

		try {
			super.addConnection(context, info);
		} catch (Exception e) {
			System.out.println("YJIOT  DisConnect IP:" + info.getClientIp() + " clientid:" + info.getClientId());
			log.error(e.getMessage());
			log.error("DisConnect Client ID:" + context.getClientId());
			super.removeConnection(context, info, null);
		}
	}


	private DeviceInfo getUser(String username) {
		System.out.println("YJIOT  getUser username:" +username );
		String sql = "select * from t_dev_info where device_id=? limit 1";
		DeviceInfo user = jdbcTemplate.queryForObject(sql, new Object[] { username },
				new BeanPropertyRowMapper<DeviceInfo>(DeviceInfo.class));
		return user;
	}

	@Override
	public SecurityContext authenticate(String username, String password, X509Certificate[] peerCertificates)
			throws SecurityException {
		SecurityContext securityContext = null;
		DeviceInfo user = getUser(username);
		System.out.println("YJIOT  Connect Account username:" +username + " password:" + password);
		if (user != null && user.getDevicePw().equals(password)) {
			securityContext = new SecurityContext(username) {
				@Override
				public Set<Principal> getPrincipals() {
					Set<Principal> groups = new HashSet<Principal>();
					groups.add(new GroupPrincipal("users"));
					return groups;
				}
			};
		} else {
			throw new SecurityException("authenticate failer user or password is worng!");
		}
		return securityContext;
	}

}
