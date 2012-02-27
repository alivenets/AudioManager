/** Copyright (c) 2012 GENIVI Alliance
 *  Copyright (c) 2012 BMW
 *
 *  @author Christian Mueller, BMW
 *
 *  @copyright
 *  {
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  }
 *
 * 
 * THIS CODE HAS BEEN GENERATED BY ENTERPRISE ARCHITECT GENIVI MODEL. PLEASE CHANGE ONLY IN ENTERPRISE ARCHITECT AND GENERATE AGAIN
 */
#if !defined(EA_1872FCAA_4ACA_4547_ABD0_F0CC01DE516C__INCLUDED_)
#define EA_1872FCAA_4ACA_4547_ABD0_F0CC01DE516C__INCLUDED_

#include <vector>
#include <string>
#include "audiomanagertypes.h"

namespace am {
class DBusWrapper;
class SocketHandler;
}


#define RoutingReceiveVersion "1.0" 
namespace am {
	/**
	 * Routing Receive sendInterface description. This class implements everything from RoutingAdapter -> Audiomanager
	 * There are two rules that have to be kept in mind when implementing against this interface:\n<b>
	 * 1. CALLS TO THIS INTERFACE ARE NOT THREAD SAFE !!!! \n
	 * 2. YOU MAY NOT THE CALLING INTERFACE DURING AN SYNCHRONOUS OR ASYNCHRONOUS CALL THAT EXPECTS A RETURN VALUE.</b>\n
	 * Violation these rules may lead to unexpected behavior! Nevertheless you can implement thread safe by using the deferred-call pattern described on the wiki which also helps to implement calls that are forbidden.\n
	 * For more information, please check CAmSerializer
	 * @author Christian Mueller
	 * @created 27-Feb-2012 6:57:33 PM
	 */
	class RoutingReceiveInterface
	{

	public:
		RoutingReceiveInterface() {

		}

		virtual ~RoutingReceiveInterface() {

		}

		/**
		 * acknowledges a asyncConnect
		 * 
		 * @param handle
		 * @param connectionID
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackConnect(const am_Handle_s handle, const am_connectionID_t connectionID, const am_Error_e error) =0;
		/**
		 * acknowledges a asyncDisconnect
		 * 
		 * @param handle
		 * @param connectionID
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackDisconnect(const am_Handle_s handle, const am_connectionID_t connectionID, const am_Error_e error) =0;
		/**
		 * acknowledges a asyncsetSinkVolume 
		 * 
		 * @param handle
		 * @param volume    The current actual value that is set 
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSinkVolumeChange(const am_Handle_s handle, const am_volume_t volume, const am_Error_e error) =0;
		/**
		 * acknowledges a asyncsetSourceVolume
		 * 
		 * @param handle    handle that belongs to the change 
		 * @param volume    the current volume
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSourceVolumeChange(const am_Handle_s handle, const am_volume_t volume, const am_Error_e error) =0;
		/**
		 * acknowlegde for asyncSetSourceState
		 * 
		 * @param handle
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSourceState(const am_Handle_s handle, const am_Error_e error) =0;
		/**
		 * acknowledges asyncSetSinkSoundProperties
		 * 
		 * @param handle
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSinkSoundProperties(const am_Handle_s handle, const am_Error_e error) =0;
		/**
		 * acknowledges asyncSetSinkSoundProperty
		 * 
		 * @param handle
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSinkSoundProperty(const am_Handle_s handle, const am_Error_e error) =0;
		/**
		 * acknowledges asyncSetSourceSoundProperties
		 * 
		 * @param handle
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSourceSoundProperties(const am_Handle_s handle, const am_Error_e error) =0;
		/**
		 * acknowledges asyncSetSourceSoundProperty
		 * 
		 * @param handle
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackSetSourceSoundProperty(const am_Handle_s handle, const am_Error_e error) =0;
		/**
		 * acknowledges asyncCrossFade
		 * 
		 * @param handle
		 * @param hotSink    this is the current hot sink, HS_INTERMEDIATE is here when a crossfading action did not reach the end
		 * @param error    E_OK on success, E_ABORTED if action was aborted, E_UNKNOWN on error
		 */
		virtual void ackCrossFading(const am_Handle_s handle, const am_HotSink_e hotSink, const am_Error_e error) =0;
		/**
		 * acknowledges a volume tick. This can be used to display volumechanges during ramps
		 * 
		 * @param handle
		 * @param sourceID
		 * @param volume
		 */
		virtual void ackSourceVolumeTick(const am_Handle_s handle, const am_sourceID_t sourceID, const am_volume_t volume) =0;
		/**
		 * acknowledges a volume tick. This can be used to display volumechanges during ramps
		 * 
		 * @param handle
		 * @param sinkID
		 * @param volume
		 */
		virtual void ackSinkVolumeTick(const am_Handle_s handle, const am_sinkID_t sinkID, const am_volume_t volume) =0;
		/**
		 * This function returns the ID to the given domainName. If already a domain is registered with this name, it will return the corresponding ID, if not it will reserve an ID but not register the domain. The other parameters of the domain will be overwritten when the domain is registered.
		 * @return E_OK on success, E_UNKNOWN on error
		 * 
		 * @param name
		 * @param domainID
		 */
		virtual am_Error_e peekDomain(const std::string& name, am_domainID_t& domainID) =0;
		/**
		 * registers a domain
		 * @return E_OK on succes, E_ALREADY_EXISTENT if already registered E_UNKOWN on error
		 * 
		 * @param domainData    domainID in am_Domain_s must be 0!
		 * @param domainID
		 */
		virtual am_Error_e registerDomain(const am_Domain_s& domainData, am_domainID_t& domainID) =0;
		/**
		 * deregisters a domain. All sources, sinks, gateways and crossfaders from that domain will be removed as well.
		 * @return E_OK on succes, E_NON_EXISTENT if not found E_UNKOWN on error
		 * 
		 * @param domainID    < the nonde of the bus
		 */
		virtual am_Error_e deregisterDomain(const am_domainID_t domainID) =0;
		/**
		 * registers a gateway. @return E_OK on succes, E_ALREADY_EXISTENT if already registered E_UNKOWN on error
		 * 
		 * @param gatewayData    In a fixed setup, the gatewayID must be below 100. In a dynamic setup, the gatewayID shall be 0. listSourceFormats and listSinkFormats are empty at registration time. Values are taken over when sources and sinks are registered.
		 * 
		 * 
		 * @param gatewayID
		 */
		virtual am_Error_e registerGateway(const am_Gateway_s& gatewayData, am_gatewayID_t& gatewayID) =0;
		/**
		 * deregisters a gateway. Also removes all sinks and sources of the controlling domain.
		 * @return E_OK on succes, E_NON_EXISTENT if not found E_UNKOWN on error
		 * 
		 * @param gatewayID    domainID of the control domain
		 */
		virtual am_Error_e deregisterGateway(const am_gatewayID_t gatewayID) =0;
		/**
		 * This function returns the ID to the given sinkName. If already a sink is registered with this name, it will return the corresponding ID, if not it will reserve an ID but not register the sink. The other parameters of the sink will be overwritten when the sink is registered.
		 * @return E_OK on success, E_UNKNOWN on error
		 * 
		 * @param name    ID is not valid since not created yet
		 * @param sinkID
		 */
		virtual am_Error_e peekSink(const std::string& name, am_sinkID_t& sinkID) =0;
		/**
		 * Registers a sink. If the sink is part of a gateway, the listconnectionFormats is copied to the gatewayInformation
		 * @return E_OK on succes, E_ALREADY_EXISTENT if already registered E_UNKOWN on error
		 * 
		 * @param sinkData    In a fixed setup, the sinkID within am_Sink_s must be below 100. In a dynamic setup the sinkID must be 0 in am_Sink_s.
		 * @param sinkID
		 */
		virtual am_Error_e registerSink(const am_Sink_s& sinkData, am_sinkID_t& sinkID) =0;
		/**
		 * deregisters a sink.
		 * @return E_OK on succes, E_NON_EXISTENT if not found E_UNKOWN on error
		 * 
		 * @param sinkID
		 */
		virtual am_Error_e deregisterSink(const am_sinkID_t sinkID) =0;
		/**
		 * This function returns the ID to the given sourceName. If already a source is registered with this name, it will return the corresponding ID, if not it will reserve an ID but not register the source. The other parameters of the source will be overwritten when the source is registered.
		 * @return E_OK on success, E_UNKNOWN on error
		 * 
		 * @param name
		 * @param sourceID
		 */
		virtual am_Error_e peekSource(const std::string& name, am_sourceID_t& sourceID) =0;
		/**
		 * registers a source.  If the source is part of a gateway, the listconnectionFormats is copied to the gatewayInformation
		 * @return E_OK on success, E_UNKNOWN on error, E_ALREADY_EXIST if either name or sourceID already exists
		 * 
		 * @param sourceData    In a fixed setup, the sourceID within am_Source_s must be below 100. In a dynamic setup the sourceID must be 0 in am_Source_s
		 * @param sourceID
		 */
		virtual am_Error_e registerSource(const am_Source_s& sourceData, am_sourceID_t& sourceID) =0;
		/**
		 * deregisters a source
		 * @return E_OK on succes, E_NON_EXISTENT if not found E_UNKOWN on error
		 * 
		 * @param sourceID
		 */
		virtual am_Error_e deregisterSource(const am_sourceID_t sourceID) =0;
		/**
		 * this function registers a crossfader.
		 * @return E_OK on succes, E_ALREADY_EXISTENT if already registered E_UNKOWN on error
		 * 
		 * @param crossfaderData    in a fixed setup, the crossfaderID must be below 100. In a dynamic setup the crossfasderID shall be 0
		 * @param crossfaderID
		 */
		virtual am_Error_e registerCrossfader(const am_Crossfader_s& crossfaderData, am_crossfaderID_t& crossfaderID) =0;
		/**
		 * this function deregisters a crossfader. removes all sources and sinks assiated as well.
		 * @return E_OK on succes, E_NON_EXISTENT if not found E_UNKOWN on error
		 * 
		 * @param crossfaderID
		 */
		virtual am_Error_e deregisterCrossfader(const am_crossfaderID_t crossfaderID) =0;
		/**
		 * this function peeks a sourceclassID. It is used by the RoutingPlugins to determine the SinkClassIDs of a sinkClass.
		 * @return E_OK on succes, E_DATABASE_ERROR on error
		 * 
		 * @param name
		 * @param sourceClassID
		 */
		virtual am_Error_e peekSourceClassID(const std::string& name, am_sourceClass_t& sourceClassID) =0;
		/**
		 * this function peeks a sourceclassID. It is used by the RoutingPlugins to determine the SinkClassIDs of a sinkClass.
		 * @return E_OK on succes, E_DATABASE_ERROR on error
		 * 
		 * @param name
		 * @param sinkClassID
		 */
		virtual am_Error_e peekSinkClassID(const std::string& name, am_sinkClass_t& sinkClassID) =0;
		/**
		 * is called when a low level interrupt changes it status.
		 * 
		 * @param sourceID
		 * @param interruptState
		 */
		virtual void hookInterruptStatusChange(const am_sourceID_t sourceID, const am_InterruptState_e interruptState) =0;
		/**
		 * This hook is called when all elements from a domain are registered.
		 * Is used by the Controller to know when all expected domains are finally registered
		 * 
		 * @param domainID
		 */
		virtual void hookDomainRegistrationComplete(const am_domainID_t domainID) =0;
		/**
		 * is called when a sink changes its availability
		 * 
		 * @param sinkID
		 * @param availability
		 */
		virtual void hookSinkAvailablityStatusChange(const am_sinkID_t sinkID, const am_Availability_s& availability) =0;
		/**
		 * is called when a source changes its availability
		 * 
		 * @param sourceID
		 * @param availability
		 */
		virtual void hookSourceAvailablityStatusChange(const am_sourceID_t sourceID, const am_Availability_s& availability) =0;
		/**
		 * is called when a domain changes its status. This used for early domains only
		 * 
		 * @param domainID
		 * @param domainState
		 */
		virtual void hookDomainStateChange(const am_domainID_t domainID, const am_DomainState_e domainState) =0;
		/**
		 * is called when the timinginformation (delay) changed for a connection.
		 * 
		 * @param connectionID
		 * @param delay
		 */
		virtual void hookTimingInformationChanged(const am_connectionID_t connectionID, const am_timeSync_t delay) =0;
		/**
		 * this function is used to send out all data that has been changed in an early state.
		 * @return E_OK on success, E_UNKNOWN on error
		 * 
		 * @param earlyData
		 */
		virtual void sendChangedData(const std::vector<am_EarlyData_s>& earlyData) =0;
		/**
		 * this function is used to retrieve a pointer to the dBusConnectionWrapper
		 * @return E_OK if pointer is valid, E_UKNOWN if AudioManager was compiled without DBus Support
		 * 
		 * @param dbusConnectionWrapper    This is a wrapper class that is needed to keep dbus inclusions away from the interface. The DBusWrapperClass will return the pointer to the DbusConnection call (getDBusConnection)
		 */
		virtual am_Error_e getDBusConnectionWrapper(DBusWrapper*& dbusConnectionWrapper) const =0;
		/**
		 * This function returns the pointer to the socketHandler. This can be used to integrate socket-based activites like communication with the mainloop of the AudioManager.
		 * returns E_OK if pointer is valid, E_UNKNOWN in case AudioManager was compiled without socketHandler support,
		 * 
		 * @param socketHandler
		 */
		virtual am_Error_e getSocketHandler(SocketHandler*& socketHandler) const =0;
		/**
		 * This function returns the version of the interface
		 * 
		 * @param version    retrieves the verison of the interface
		 */
		virtual void  getInterfaceVersion(std::string& version) const =0;
		/**
		 * confirms the setRoutingReady Command
		 * 
		 * @param handle    the handle that was given via setRoutingReady
		 */
		virtual void  confirmRoutingReady(const uint16_t handle) const =0;
		/**
		 * confirms the setRoutingRundown Command
		 * 
		 * @param handle    handle that was given via setRoutingRundown
		 */
		virtual void  confirmRoutingRundown(const uint16_t handle) const =0;

	};
}
#endif // !defined(EA_1872FCAA_4ACA_4547_ABD0_F0CC01DE516C__INCLUDED_)
