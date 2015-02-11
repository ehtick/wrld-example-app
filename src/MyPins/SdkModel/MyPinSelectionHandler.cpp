// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "MyPinSelectionHandler.h"
#include "MyPinDetailsModelSelectedMessage.h"
#include "FlurryWrapper.h"

namespace ExampleApp
{
    namespace MyPins
    {
        namespace SdkModel
        {
            MyPinSelectionHandler::MyPinSelectionHandler(MyPinModel& myPinModel,
                    ExampleAppMessaging::TMessageBus& messageBus)
                : m_myPinModel(myPinModel)
                , m_messageBus(messageBus)
            {

            }

            void MyPinSelectionHandler::SelectPin()
            {
                FLURRY_SET_EVENT("Selected MyPin", "Name", m_myPinModel.GetTitle().c_str());
                m_messageBus.Publish(MyPinDetails::MyPinDetailsModelSelectedMessage(m_myPinModel));
            }
        }
    }
}
