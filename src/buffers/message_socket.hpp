
#ifndef REBOOST_MESSAGE_SOCKET_HPP_
#define REBOOST_MESSAGE_SOCKET_HPP_

#include<boost/unordered_set.hpp>
#include<boost/foreach.hpp>

namespace reboost {

using boost::unordered_set;

/**
 * A message socket interface to send / receive messages.
 *
 * @author Sebastian Mies <mies@reboost.org>
 */
class message_socket {
public:
	/// max. delay in milliseconds
	typedef unsigned short delay_t;

	/// A simple, pure-virtual message listener.
	class listener {
	protected:
		/// destructor
		virtual ~message_listener() = 0;

		/// called by message_tranceiver, when a message has been received
		virtual void on_message( message_socket* mt, const message_t msg ) = 0;

		/// called by message_tranceiver, when a message has been locally dropped
		virtual void on_message_drop( message_socket* mt, message_t msg ) = 0;
	};

public:
	/// destructor
	virtual ~message_socket() = 0;

	/// queues a message with the given delay
	virtual bool send( message_t msg, delay_t max_delay = 0 ) = 0;

	/// listens for a new message
	virtual void receive() = 0;

	/// automatically listens for a new message
	virtual void set_auto_receive( bool autoreceive = true ) = 0;

	/// adds a message listener
	inline void add_listener( listener* listener ) {
		listeners.insert( listener );
	}

	/// removes a message listener
	inline void remove_listener( listener* listener ) {
		listeners.erase( listener );
	}

private:
	unordered_set<message_listener*> listeners;

protected:
	/// fires on_message event
	inline void fire_message( const message_t msg ) {
		BOOST_FOREACH( listener* ml, listeners )
			ml->on_message( this, msg );
	}
	/// fires on_message_drop event
	inline void fire_message_drop( message_t msg ) {
		BOOST_FOREACH( listener* ml, listeners )
			ml->on_message_drop( this, msg );
	}
};

}

#endif /* REBOOST_MESSAGE_SOCKET_HPP_ */
