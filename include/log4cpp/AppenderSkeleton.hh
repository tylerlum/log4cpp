/*
 * AppenderSkeleton.hh
 *
 * Copyright 2001, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2001, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_APPENDERSKELETON_HH
#define _LOG4CPP_APPENDERSKELETON_HH

#include "log4cpp/Hints.hh"
#include "log4cpp/Appender.hh"

namespace log4cpp {

    /**
     *  Implement this interface for your own strategies for printing log
     *  statements. 
     **/
    class AppenderSkeleton : public Appender {
        protected:
        /**
         * Constructor for AppenderSkeleton. Will only be used in 
         * getAppender() (and in derived classes of course).
         * @param name The name of this Appender.
         **/
        AppenderSkeleton(const std::string& name);

        public:
        /**
         * Destructor for AppenderSkeleton.
         **/
        virtual ~AppenderSkeleton();
        
        /**
         * Log in Appender specific way. 
         * @param event  The LoggingEvent to log. 
         **/
        virtual void doAppend(const LoggingEvent& event);

        /**
         * Reopens the output destination of this Appender, e.g. the logfile 
         * or TCP socket.
         * @returns false if an error occured during reopening, true otherwise.
         **/
        virtual bool reopen();

        /**
         * Release any resources allocated within the appender such as file
         * handles, network connections, etc.
         **/
        virtual void close() = 0;

        /**
         * Check if the appender uses a layout.
         * 
         * @returns true if the appender implementation requires a layout.
         **/
        virtual bool requiresLayout() const = 0;

        /**
         * Set the Layout for this appender.
         * @param layout The layout to use.
         **/
        virtual void setLayout(Layout* layout) = 0;

        /**
         * Set the treshold priority of this Appender. The Appender will not
         * appender LoggingEvents with a priority lower than the treshold.
         * Use Priority::NOTSET to disable treshold checking.
         * @param priority The priority to set.
         **/
        virtual void setTreshold(Priority::Value priority);

        virtual Priority::Value getTreshold();

        protected:
        /**
         * Log in Appender specific way. Sublclasses of Appender should
         * implement this method to perform actual logging.
         * @param event  The LoggingEvent to log. 
         **/
        virtual void _append(const LoggingEvent& event) = 0;

        
        private:
        Priority::Value _treshold;
    };
}

#endif // _LOG4CPP_APPENDERSKELETON_HH
