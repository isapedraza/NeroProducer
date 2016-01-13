#ifndef NERO_PUPPIFATJETS_H
#define NERO_PUPPIFATJETS_H

#include "NeroProducer/Nero/interface/NeroCollection.hpp"
#include "NeroProducer/Core/interface/BarePuppiFatJets.hpp"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

class NeroPuppiFatJets : virtual public NeroCollection, 
    virtual public BarePuppiFatJets
{
    public:
        NeroPuppiFatJets();
        ~NeroPuppiFatJets();
        int analyze(const edm::Event& iEvent);
        virtual inline string name(){return "NeroPuppiFatJets";};
        void init() override;

        // --- specific fuctions
        // --- Handle
        edm::Handle<pat::JetCollection> handle;	
        edm::Handle<double> rho_handle;

        // --- Token
        edm::EDGetTokenT<pat::JetCollection> token;
        edm::EDGetTokenT<double> rho_token;

        // --- configuration
        float mMinPt;
        int   mMinNjets;
        float mMaxEta;
        string mMinId;
        bool mUseCA15;
        FactorizedJetCorrector *mMCJetCorrector;   // needed for puppi CA15 jets
        FactorizedJetCorrector *mDataJetCorrector; 

};


#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
